#include "MyRenderTestLibrary.h"

#include "Engine/TextureRenderTarget2D.h"
#include "CanvasTypes.h"
#include "TextureResource.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"

void UMyRenderTestLibrary::ExecuteCustomShader(UTextureRenderTarget2D* RenderTarget, FLinearColor Color)
{
    // 1. ゲームスレッド側での完全防御
    if (!RenderTarget)
    {
        return;
    }

    // ★重要: レンダーターゲットのリソースが準備されていない場合は即時更新
    if (!RenderTarget->GetResource())
    {
        RenderTarget->UpdateResourceImmediate(false);
    }

    FTextureRenderTargetResource* Resource = RenderTarget->GameThread_GetRenderTargetResource();

    // ★重要: リソースが存在し、かつ初期化（InitResource）が完了しているか判定
    if (!Resource || !Resource->IsInitialized())
    {
        return;
    }

    // 2. 安全が確認されたリソースのみ描画スレッドへ委託
    ENQUEUE_RENDER_COMMAND(ExecuteCustomShaderCommand)(
        [Resource, Color](FRHICommandListImmediate& RHICmdList)
        {
            if (!Resource || !Resource->IsInitialized())
            {
                return;
            }

            FRHITexture* TextureRHI = Resource->GetTextureRHI();
            if (!TextureRHI || !TextureRHI->IsValid())
            {
                return;
            }

            FRDGBuilder GraphBuilder(RHICmdList);

            // 3. RDG に外部テクスチャとして登録
            FRDGTextureRef OutputTexture = RegisterExternalTexture(
                GraphBuilder,
                TextureRHI,
                TEXT("CustomShaderOutput")
            );

            if (!OutputTexture)
            {
                return;
            }

            // 4. クリアパス（予定表へのタスク追加）
            AddClearRenderTargetPass(GraphBuilder, OutputTexture, Color);

            // 5. 予定表（グラフ）を一括実行！
            GraphBuilder.Execute();
        }
        );
}
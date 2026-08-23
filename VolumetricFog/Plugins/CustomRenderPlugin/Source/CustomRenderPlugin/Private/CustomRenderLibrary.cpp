#include "CustomRenderLibrary.h"
#include "MyCustomShader.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"
#include "PixelShaderUtils.h"
#include "TextureResource.h"

void UCustomRenderLibrary::DrawCustomShaderToRenderTarget(UTextureRenderTarget2D* OutputRenderTarget, FLinearColor Color)
{
    if (!OutputRenderTarget) return;

    FTextureRenderTargetResource* RenderTargetResource = OutputRenderTarget->GameThread_GetRenderTargetResource();

    ENQUEUE_RENDER_COMMAND(DrawCustomShaderCommand)(
        [RenderTargetResource, Color](FRHICommandListImmediate& RHICmdList)
        {
            FRDGBuilder GraphBuilder(RHICmdList);

            // 1. GetRenderTargetTexture() から直接 RDG テクスチャとして登録
            FRHITexture* RHITexture = RenderTargetResource->GetRenderTargetTexture();
            if (!RHITexture) return;

            FRDGTextureRef OutputTexture = GraphBuilder.RegisterExternalTexture(
                CreateRenderTarget(RHITexture, TEXT("CustomRenderOutput"))
            );

            // 2. パラメータ設定
            FMyCustomPixelShader::FParameters* PassParameters = GraphBuilder.AllocParameters<FMyCustomPixelShader::FParameters>();
            PassParameters->MyColor = Color;
            PassParameters->RenderTargets[0] = FRenderTargetBinding(OutputTexture, ERenderTargetLoadAction::ENoAction);

            // 3. パスの追加と実行
            FGlobalShaderMap* ShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
            TShaderMapRef<FMyCustomPixelShader> PixelShader(ShaderMap);

            FPixelShaderUtils::AddFullscreenPass(
                GraphBuilder,
                ShaderMap,
                RDG_EVENT_NAME("CustomRenderPlugin_Pass"),
                PixelShader,
                PassParameters,
                FIntRect(0, 0, RHITexture->GetDesc().Extent.X, RHITexture->GetDesc().Extent.Y)
            );

            GraphBuilder.Execute();
        }
        );
}
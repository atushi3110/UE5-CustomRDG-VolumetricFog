#include "CustomRenderLibrary.h"
#include "MyCustomShader.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"
#include "PixelShaderUtils.h"
#include "TextureResource.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "VolumetricCloudManager.h"
#include "EngineUtils.h"

// =============================================================================
// ★ 11行目〜13行目追加: 関数の外（グローバルスコープ）でクリア用構造体を定義
// =============================================================================
BEGIN_SHADER_PARAMETER_STRUCT(FClearDepthParameters, )
    RENDER_TARGET_BINDING_SLOTS()
END_SHADER_PARAMETER_STRUCT()

void UCustomRenderLibrary::DrawCustomShaderToRenderTarget(
    UObject* WorldContextObject,
    UTextureRenderTarget2D* OutputRenderTarget,
    float Time,
    FLinearColor Color)
{
    if (!OutputRenderTarget || !WorldContextObject) return;

    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
    if (!World) return;

    float PassWorldTime = World->GetTimeSeconds();

    // 1. クラウドマネージャーからのパラメータ取得
    FLinearColor PassCloudColor = Color;
    int32 PassDebugMode = 0;

    // ★ デフォルト値の設定
    float PassCloudCoverage = 0.38f;
    float PassCloudDensity = 4.0f;
    FVector3f PassWindDirection = FVector3f(1.0f, 0.2f, 0.0f).GetSafeNormal();
    float PassWindSpeed = 50.0f;

    for (TActorIterator<AVolumetricCloudManager> It(World); It; ++It)
    {
        if (AVolumetricCloudManager* Manager = *It)
        {
            PassCloudColor = Manager->CloudColor;
            PassDebugMode = Manager->GetDebugModeAsInt();

            // ★ マネージャーの最新設定値を反映
            PassCloudCoverage = Manager->CloudCoverage;
            PassCloudDensity = Manager->CloudDensity;
            PassWindDirection = FVector3f(Manager->WindDirection.GetSafeNormal());
            PassWindSpeed = Manager->WindSpeed;
            break;
        }
    }

    APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
    if (!PC || !PC->PlayerCameraManager) return;

    // 1. カメラの位置と回転を正しく取得
    FVector CameraPosition;
    FRotator CameraRotation;
    PC->GetPlayerViewPoint(CameraPosition, CameraRotation);

    FTextureRenderTargetResource* RenderTargetResource = OutputRenderTarget->GameThread_GetRenderTargetResource();
    if (!RenderTargetResource) return;

    FIntPoint Size = RenderTargetResource->GetSizeXY();
    if (Size.X <= 0 || Size.Y <= 0) return;

    float FOVDeg = PC->PlayerCameraManager->GetFOVAngle();
    float AspectRatio = (float)Size.X / (float)Size.Y;

    // -----------------------------------------------------------------------------
    // ★ 修正版：UEの標準計算関数 (FMatrix) を用いた正確な View / Proj 行列
    // -----------------------------------------------------------------------------

    // 1. CameraRotation から正規化された 3 軸ベクトルを取得
    FVector ForwardVector = CameraRotation.Vector();
    FVector RightVector = FRotationMatrix(CameraRotation).GetScaledAxis(EAxis::Y);
    FVector UpVector = FRotationMatrix(CameraRotation).GetScaledAxis(EAxis::Z);

    // 2. FLookAtMatrix でカメラ視点行列（ViewMatrix）を生成
    FMatrix ViewMatrix = FLookAtMatrix(CameraPosition, CameraPosition + ForwardVector * 100.0f, UpVector);

    // 3. Reversed-Z Perspective 行列の作成
    float HalfFOV = FMath::DegreesToRadians(FOVDeg * 0.5f);
    float MinZ = GNearClippingPlane;
    FMatrix ProjMatrix = FReversedZPerspectiveMatrix(HalfFOV, AspectRatio, 1.0f, MinZ);

    // 4. ViewProj 行列および逆行列の計算（UE標準の順序: View * Proj）
    FMatrix ViewProj = ViewMatrix * ProjMatrix;
    FMatrix InvViewProj = ViewProj.Inverse();
    FMatrix44f PassInvViewProj = FMatrix44f(InvViewProj);

    FVector3f PassCameraPos = (FVector3f)CameraPosition;
    FVector2f PassScreenSize = FVector2f((float)Size.X, (float)Size.Y);

    // -----------------------------------------------------------------------------
    // ★ デバッグ2: C++側でカメラの向きと行列の値を画面とログに出力
    // -----------------------------------------------------------------------------
    if (GEngine)
    {
        FString DebugStr = FString::Printf(TEXT("CamPos: %s | CamRot: %s | FOV: %.1f"),
            *CameraPosition.ToString(), *CameraRotation.ToString(), FOVDeg);
        GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Yellow, DebugStr);
    }

    UE_LOG(LogTemp, Warning, TEXT("InvViewProj: %s"), *InvViewProj.ToString());

    // 2. 描画スレッドへのタスク発行
    ENQUEUE_RENDER_COMMAND(DrawCustomShaderCommand)(
        [
            RenderTargetResource, PassCameraPos, PassInvViewProj, PassScreenSize,
            PassWorldTime, PassCloudColor, PassDebugMode,
            PassCloudCoverage, PassCloudDensity, PassWindDirection, PassWindSpeed // ★ キャプチャ
        ](FRHICommandListImmediate& RHICmdList)
        {
            FRDGBuilder GraphBuilder(RHICmdList);

            FRHITexture* RHITexture = RenderTargetResource->GetRenderTargetTexture();
            if (!RHITexture) return;

            FRDGTextureRef OutputTexture = GraphBuilder.RegisterExternalTexture(
                CreateRenderTarget(RHITexture, TEXT("CustomRenderOutput"))
            );

            // 1. SceneDepth テクスチャの定義
            FRDGTextureDesc DepthDesc = FRDGTextureDesc::Create2D(
                RHITexture->GetDesc().Extent,
                PF_DepthStencil,
                FClearValueBinding::DepthZero, // ★ ここで 0.0f (Reversed-Zにおける無限遠) を指定
                TexCreate_DepthStencilTargetable | TexCreate_ShaderResource
            );

            FRDGTextureRef DepthRDGTexture = GraphBuilder.CreateTexture(DepthDesc, TEXT("FallbackSceneDepth"));

            // =============================================================================
            // ★ 105行目〜107行目修正: グローバル定義された FClearDepthParameters を割り当て
            // =============================================================================
            auto* ClearParameters = GraphBuilder.AllocParameters<FClearDepthParameters>();
            ClearParameters->RenderTargets.DepthStencil = FDepthStencilBinding(
                DepthRDGTexture,
                nullptr, // StencilTexture（未使用のため nullptr）
                ERenderTargetLoadAction::EClear,
                ERenderTargetLoadAction::ENoAction,
                FExclusiveDepthStencil::DepthWrite_StencilNop
            );

            GraphBuilder.AddPass(
                RDG_EVENT_NAME("ClearFallbackDepth"),
                ClearParameters,
                ERDGPassFlags::Raster,
                [](FRHICommandList& RHICmdList) {}
            );

            // 2. メインシェーダーパスのパラメータ割り当て
            FMyCustomPixelShader::FParameters* PassParameters = GraphBuilder.AllocParameters<FMyCustomPixelShader::FParameters>();

            PassParameters->CameraPosition = PassCameraPos;
            PassParameters->InvViewProjectionMatrix = PassInvViewProj;
            PassParameters->ScreenSize = PassScreenSize;
            PassParameters->MyColor = PassCloudColor;
            PassParameters->DebugMode = PassDebugMode;
            PassParameters->Time = PassWorldTime;

            PassParameters->CloudCoverage = PassCloudCoverage;
            PassParameters->CloudDensity = PassCloudDensity;
            PassParameters->WindDirection = PassWindDirection;
            PassParameters->WindSpeed = PassWindSpeed;

            FVector3f LightDir = FVector3f(0.5f, 0.5f, -1.0f).GetSafeNormal();
            PassParameters->LightDirection = LightDir;
            PassParameters->LightColor = FLinearColor(1.0f, 0.95f, 0.8f, 3.0f);

            PassParameters->SceneDepthTexture = DepthRDGTexture;
            PassParameters->SceneDepthTextureSampler = TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp>::GetRHI();

            PassParameters->RenderTargets[0] = FRenderTargetBinding(OutputTexture, ERenderTargetLoadAction::EClear);

            FGlobalShaderMap* ShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
            TShaderMapRef<FMyCustomPixelShader> PixelShader(ShaderMap);

            FRHIBlendState* AlphaBlendState = TStaticBlendState<
                CW_RGBA,
                BO_Add, BF_One, BF_InverseSourceAlpha,
                BO_Add, BF_Zero, BF_One
            >::GetRHI();

            FPixelShaderUtils::AddFullscreenPass(
                GraphBuilder,
                ShaderMap,
                RDG_EVENT_NAME("CustomRenderPlugin_Pass"),
                PixelShader,
                PassParameters,
                FIntRect(0, 0, RHITexture->GetDesc().Extent.X, RHITexture->GetDesc().Extent.Y),
                AlphaBlendState
            );

            GraphBuilder.Execute();
        }
        );
}
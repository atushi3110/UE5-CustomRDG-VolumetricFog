#include "CustomRenderLibrary.h"
#include "MyCustomShader.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"
#include "PixelShaderUtils.h"
#include "TextureResource.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

void UCustomRenderLibrary::DrawCustomShaderToRenderTarget(
    UObject* WorldContextObject,
    UTextureRenderTarget2D* OutputRenderTarget,
    float Time,
    FLinearColor Color)
{
    if (!OutputRenderTarget || !WorldContextObject) return;

    // 1. World の取得
    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
    if (!World) return;

    APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
    if (!PC || !PC->PlayerCameraManager) return;

    // 2. カメラ位置と回転の取得
    FVector CameraPosition = FVector::ZeroVector;
    FRotator CameraRotation = FRotator::ZeroRotator;
    PC->GetPlayerViewPoint(CameraPosition, CameraRotation);

    // 3. Render Target の解像度を取得
    FTextureRenderTargetResource* RenderTargetResource = OutputRenderTarget->GameThread_GetRenderTargetResource();
    if (!RenderTargetResource) return;

    FIntPoint Size = RenderTargetResource->GetSizeXY();
    if (Size.X <= 0 || Size.Y <= 0) return;

    // 4. 行列およびパラメータの計算
    float FOVRad = FMath::DegreesToRadians(PC->PlayerCameraManager->GetFOVAngle());
    float AspectRatio = (float)Size.X / (float)Size.Y;

    // A. プロジェクション行列
    FMatrix ProjMatrix = FReversedZPerspectiveMatrix(FOVRad * 0.5f, AspectRatio, 1.0f, GNearClippingPlane);

    // B. カメラの回転・位置から正確な View 行列を構築
    // Unreal Engine の FInverseRotationMatrix を使用して回転の逆行列を正しく適用します
    FMatrix ViewRotationMatrix = FInverseRotationMatrix(CameraRotation);
    FMatrix ViewTranslationMatrix = FTranslationMatrix(-CameraPosition);
    FMatrix ViewMatrix = ViewTranslationMatrix * ViewRotationMatrix;

    // C. InvViewProj 行列の計算 (Clip Space -> World Space)
    FMatrix InvViewProj = ProjMatrix.Inverse() * ViewMatrix.Inverse();

    FVector3f PassCameraPos = (FVector3f)CameraPosition;
    FMatrix44f PassInvViewProj = (FMatrix44f)InvViewProj;
    FVector2f PassScreenSize = FVector2f((float)Size.X, (float)Size.Y);

    // 5. レンダリングコマンドの発行
    ENQUEUE_RENDER_COMMAND(DrawCustomShaderCommand)(
        [RenderTargetResource, PassCameraPos, PassInvViewProj, PassScreenSize, Time, Color](FRHICommandListImmediate& RHICmdList)
        {
            FRDGBuilder GraphBuilder(RHICmdList);

            FRHITexture* RHITexture = RenderTargetResource->GetRenderTargetTexture();
            if (!RHITexture) return;

            FRDGTextureRef OutputTexture = GraphBuilder.RegisterExternalTexture(
                CreateRenderTarget(RHITexture, TEXT("CustomRenderOutput"))
            );

            // パラメータ構造体の生成
            FMyCustomPixelShader::FParameters* PassParameters = GraphBuilder.AllocParameters<FMyCustomPixelShader::FParameters>();
            PassParameters->CameraPosition = PassCameraPos;
            PassParameters->InvViewProjectionMatrix = PassInvViewProj;
            PassParameters->ScreenSize = PassScreenSize;
            PassParameters->Time = Time;
            PassParameters->MyColor = Color;

            FVector3f LightDir = FVector3f(0.5f, 0.5f, -1.0f).GetSafeNormal();
            PassParameters->LightDirection = LightDir;

            // 太陽の色と強度（RGB + アルファ/強度）
            PassParameters->LightColor = FLinearColor(1.0f, 0.95f, 0.8f, 3.0f); // ほんのり温かみのある白色（強度3.0）

            // レンダーターゲットの設定
            PassParameters->RenderTargets[0] = FRenderTargetBinding(OutputTexture, ERenderTargetLoadAction::ENoAction);

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
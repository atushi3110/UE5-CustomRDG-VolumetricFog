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

void UCustomRenderLibrary::DrawCustomShaderToRenderTarget(
    UObject* WorldContextObject,
    UTextureRenderTarget2D* OutputRenderTarget,
    float Time,
    FLinearColor Color)
{
    if (!OutputRenderTarget || !WorldContextObject) return;

    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
    if (!World) return;

    // 1. クラウドマネージャーからのパラメータ取得
    FLinearColor PassCloudColor = Color;
    int32 PassDebugMode = 0;

    for (TActorIterator<AVolumetricCloudManager> It(World); It; ++It)
    {
        if (AVolumetricCloudManager* Manager = *It)
        {
            PassCloudColor = Manager->CloudColor;
            PassDebugMode = Manager->GetDebugModeAsInt();
            break;
        }
    }

    APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
    if (!PC || !PC->PlayerCameraManager) return;

    // --- カメラ・ ViewProjection 行列の計算 ---
    FVector CameraPosition = FVector::ZeroVector;
    FRotator CameraRotation = FRotator::ZeroRotator;
    PC->GetPlayerViewPoint(CameraPosition, CameraRotation);

    FTextureRenderTargetResource* RenderTargetResource = OutputRenderTarget->GameThread_GetRenderTargetResource();
    if (!RenderTargetResource) return;

    FIntPoint Size = RenderTargetResource->GetSizeXY();
    if (Size.X <= 0 || Size.Y <= 0) return;

    float FOVDeg = PC->PlayerCameraManager->GetFOVAngle();
    float FOVRad = FMath::DegreesToRadians(FOVDeg);
    float AspectRatio = (float)Size.X / (float)Size.Y;

    // UEのワールド座標系（X前, Y右, Z上）からビュー座標系（X右, Y上, Z前）への変換基底
    const FMatrix ViewRotationMatrix = FMatrix(
        FPlane(0, 0, 1, 0),
        FPlane(1, 0, 0, 0),
        FPlane(0, 1, 0, 0),
        FPlane(0, 0, 0, 1)
    );

    // 正確な View 行列の作成
    FMatrix ViewMatrix = FTranslationMatrix(-CameraPosition) * FInverseRotationMatrix(CameraRotation) * ViewRotationMatrix;

    // Reversed-Z Perspective 行列
    FMatrix ProjMatrix = FReversedZPerspectiveMatrix(FOVRad * 0.5f, AspectRatio, 1.0f, GNearClippingPlane);

    // ViewProjection 逆行列（GetTransposed は不要）
    FMatrix InvViewProj = (ViewMatrix * ProjMatrix).Inverse();
    FMatrix44f PassInvViewProj = FMatrix44f(InvViewProj);

    FVector3f PassCameraPos = (FVector3f)CameraPosition;
    FVector2f PassScreenSize = FVector2f((float)Size.X, (float)Size.Y);

    // 2. 描画スレッドへのタスク発行
    ENQUEUE_RENDER_COMMAND(DrawCustomShaderCommand)(
        [RenderTargetResource, PassCameraPos, PassInvViewProj, PassScreenSize, Time, PassCloudColor, PassDebugMode](FRHICommandListImmediate& RHICmdList)
        {
            FRDGBuilder GraphBuilder(RHICmdList);

            FRHITexture* RHITexture = RenderTargetResource->GetRenderTargetTexture();
            if (!RHITexture) return;

            FRDGTextureRef OutputTexture = GraphBuilder.RegisterExternalTexture(
                CreateRenderTarget(RHITexture, TEXT("CustomRenderOutput"))
            );

            FMyCustomPixelShader::FParameters* PassParameters = GraphBuilder.AllocParameters<FMyCustomPixelShader::FParameters>();
            PassParameters->CameraPosition = PassCameraPos;
            PassParameters->InvViewProjectionMatrix = PassInvViewProj;
            PassParameters->ScreenSize = PassScreenSize;
            PassParameters->Time = Time;
            PassParameters->MyColor = PassCloudColor;
            PassParameters->DebugMode = PassDebugMode;

            FVector3f LightDir = FVector3f(0.5f, 0.5f, -1.0f).GetSafeNormal();
            PassParameters->LightDirection = LightDir;
            PassParameters->LightColor = FLinearColor(1.0f, 0.95f, 0.8f, 3.0f);

            FGlobalShaderMap* ShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
            TShaderMapRef<FMyCustomPixelShader> PixelShader(ShaderMap);

            PassParameters->RenderTargets[0] = FRenderTargetBinding(OutputTexture, ERenderTargetLoadAction::EClear);

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
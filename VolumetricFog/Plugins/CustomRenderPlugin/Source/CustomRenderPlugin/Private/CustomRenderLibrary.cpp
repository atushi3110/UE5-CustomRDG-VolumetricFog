#include "CustomRenderLibrary.h"
#include "MyCustomShader.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"
#include "PixelShaderUtils.h"
#include "TextureResource.h"

void UCustomRenderLibrary::DrawCustomShaderToRenderTarget(
    UTextureRenderTarget2D* OutputRenderTarget,
    FVector CameraPosition,
    FMatrix InvViewProjectionMatrix,
    float Time,
    FLinearColor Color)
{
    if (!OutputRenderTarget) return;

    FTextureRenderTargetResource* RenderTargetResource = OutputRenderTarget->GameThread_GetRenderTargetResource();

    // LWC(Large World Coordinates) から float 精度へ安全にキャスト
    FVector3f PassCameraPos = (FVector3f)CameraPosition;
    FMatrix44f PassInvViewProj = (FMatrix44f)InvViewProjectionMatrix;

    ENQUEUE_RENDER_COMMAND(DrawCustomShaderCommand)(
        [RenderTargetResource, PassCameraPos, PassInvViewProj, Time, Color](FRHICommandListImmediate& RHICmdList)
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
            PassParameters->Time = Time;
            PassParameters->MyColor = Color;
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
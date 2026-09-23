#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"

class FMyCustomPixelShader : public FGlobalShader
{
    DECLARE_GLOBAL_SHADER(FMyCustomPixelShader);
    SHADER_USE_PARAMETER_STRUCT(FMyCustomPixelShader, FGlobalShader);

    BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
        SHADER_PARAMETER(FVector3f, CameraPosition)
        SHADER_PARAMETER(FMatrix44f, InvViewProjectionMatrix)
        SHADER_PARAMETER(FVector2f, ScreenSize)
        SHADER_PARAMETER(float, Time)
        SHADER_PARAMETER(FLinearColor, MyColor)
        SHADER_PARAMETER(FVector3f, LightDirection)
        SHADER_PARAMETER(FLinearColor, LightColor)
        SHADER_PARAMETER(int32, DebugMode)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, SceneDepthTexture)
        SHADER_PARAMETER_SAMPLER(SamplerState, SceneDepthTextureSampler)
        SHADER_PARAMETER(float, CloudCoverage)
        SHADER_PARAMETER(float, CloudDensity)
        SHADER_PARAMETER(FVector3f,WindDirection)
        SHADER_PARAMETER(float,WindSpeed)
        RENDER_TARGET_BINDING_SLOTS()
    END_SHADER_PARAMETER_STRUCT()


    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }
};
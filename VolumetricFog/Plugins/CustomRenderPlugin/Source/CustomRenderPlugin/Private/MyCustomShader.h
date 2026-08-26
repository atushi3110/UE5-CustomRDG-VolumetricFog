#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"

class FMyCustomPixelShader : public FGlobalShader
{
public:
    DECLARE_GLOBAL_SHADER(FMyCustomPixelShader);
    SHADER_USE_PARAMETER_STRUCT(FMyCustomPixelShader, FGlobalShader);

    BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
        SHADER_PARAMETER(FVector3f, CameraPosition)
        SHADER_PARAMETER(FMatrix44f, InvViewProjectionMatrix)
        SHADER_PARAMETER(FVector2f, ScreenSize) // Åö Ç±Ç±Çí«â¡
        SHADER_PARAMETER(float, Time)
        SHADER_PARAMETER(FLinearColor, MyColor)
        RENDER_TARGET_BINDING_SLOTS()
    END_SHADER_PARAMETER_STRUCT()

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }
};
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
        SHADER_PARAMETER(FLinearColor, MyColor)
        RENDER_TARGET_BINDING_SLOTS()
    END_SHADER_PARAMETER_STRUCT()

    // ※ 自前で定義していた FMyCustomPixelShader() コンストラクターはマクロと衝突するため削除します

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }
};
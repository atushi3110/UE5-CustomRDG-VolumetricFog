#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/TextureRenderTarget2D.h"
#include "CustomRenderLibrary.generated.h"

UCLASS()
class CUSTOMRENDERPLUGIN_API UCustomRenderLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // WorldContextObject を追加し、BPからは World context だけ渡せばカメラ行列を自動計算
    UFUNCTION(BlueprintCallable, Category = "CustomRender", meta = (WorldContext = "WorldContextObject"))
    static void DrawCustomShaderToRenderTarget(
        UObject* WorldContextObject,
        UTextureRenderTarget2D* OutputRenderTarget,
        float Time,
        FLinearColor Color
    );
};
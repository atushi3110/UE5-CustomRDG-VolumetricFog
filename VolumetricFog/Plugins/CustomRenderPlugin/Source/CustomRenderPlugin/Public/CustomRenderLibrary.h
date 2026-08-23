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
    UFUNCTION(BlueprintCallable, Category = "CustomRender")
    static void DrawCustomShaderToRenderTarget(UTextureRenderTarget2D* OutputRenderTarget, FLinearColor Color);
};
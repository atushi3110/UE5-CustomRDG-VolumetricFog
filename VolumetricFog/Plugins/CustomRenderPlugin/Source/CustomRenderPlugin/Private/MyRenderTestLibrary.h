#pragma once
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyRenderTestLibrary.generated.h"

UCLASS()
class CUSTOMRENDERPLUGIN_API UMyRenderTestLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // ブループリントから呼び出して、指定したレンダーターゲットを赤く染める関数
    UFUNCTION(BlueprintCallable, Category = "CustomRender")
    static void ExecuteCustomShader(UTextureRenderTarget2D* RenderTarget, FLinearColor Color);
};
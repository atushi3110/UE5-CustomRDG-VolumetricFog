// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VolumetricCloudManager.generated.h"

// デバッグビューモードの列挙型
UENUM(BlueprintType)
enum class ECloudDebugMode : uint8
{
	Normal      UMETA(DisplayName = "0: Normal Rendering"),
	Heatmap     UMETA(DisplayName = "1: Step Heatmap"),
	DensityOnly UMETA(DisplayName = "2: Density Field Only"),
	AlphaOnly   UMETA(DisplayName = "3: Alpha Channel Only")
};

UCLASS()
class CUSTOMRENDERPLUGIN_API AVolumetricCloudManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVolumetricCloudManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    // -------------------------------------------------------------------------
    // エディタの詳細パネルから変更可能なパラメータ
    // -------------------------------------------------------------------------
    // シェーダーに渡すデバッグモード (0: Normal, 1: Heatmap, 2: Density, 3: Alpha)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Debug")
    ECloudDebugMode DebugMode = ECloudDebugMode::Normal;

    // 雲の基本色
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Rendering")
    FLinearColor CloudColor = FLinearColor::White;

    // 雲の密度の倍率（将来的なパラメータ動的変更用）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Rendering", meta = (ClampMin = "0.0", ClampMax = "5.0"))
    float CustomDensity = 1.0f;

    // ★ デバッグモードの整数値を返すヘルパー関数
    int32 GetDebugModeAsInt() const { return static_cast<int32>(DebugMode); }

};

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

    // デバッグ表示モード
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Debug")
    ECloudDebugMode DebugMode = ECloudDebugMode::Normal;

    // 雲の基本色
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Rendering")
    FLinearColor CloudColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // 雲のカバー率（量） 0.0（空域のみ）〜 1.0（全域覆う）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Parameters", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float CloudCoverage = 0.38f;

    // 雲の全体密度（厚み・濃度）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Parameters", meta = (ClampMin = "0.1", ClampMax = "10.0"))
    float CloudDensity = 4.0f;

    // 風向ベクトル (X, Y, Z)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Wind")
    FVector WindDirection = FVector(1.0f, 0.2f, 0.0f);

    // 風速
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Wind", meta = (ClampMin = "0.0", ClampMax = "500.0"))
    float WindSpeed = 50.0f;

    // デバッグモードの整数値を返すヘルパー関数
    int32 GetDebugModeAsInt() const { return static_cast<int32>(DebugMode); }
};
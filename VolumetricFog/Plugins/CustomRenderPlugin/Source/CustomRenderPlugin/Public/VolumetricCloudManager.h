// VolumetricCloudManager.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DirectionalLight.h"
#include "Components/DirectionalLightComponent.h"
#include "Curves/CurveLinearColor.h"
#include "Materials/MaterialParameterCollection.h"
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
    AVolumetricCloudManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // -------------------------------------------------------------------------
    // 設定・連携（Config）
    // -------------------------------------------------------------------------

    // アセットを割り当てるMaterial Parameter Collection
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Config")
    UMaterialParameterCollection* FogMPC;

    // 連動させる太陽（Directional Light）の参照
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Environment")
    ADirectionalLight* SunLight;

    // 時刻に応じた太陽光・雲の色を設定するカラーカーブ (X軸: 0~24時間, Y軸: Color)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Environment")
    UCurveLinearColor* SunColorCurve;

    // -------------------------------------------------------------------------
    // エディタ・Blueprint・シーケンサーから変更可能なパラメータ
    // -------------------------------------------------------------------------

    // デバッグ表示モード
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Debug")
    ECloudDebugMode DebugMode = ECloudDebugMode::Normal;

    // 雲の基本色
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category = "Cloud | Rendering")
    FLinearColor CloudColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // 雲のカバー率（量） 0.0（空域のみ）〜 1.0（全域覆う）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category = "Cloud | Parameters", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float CloudCoverage = 0.38f;

    // 雲の全体密度（厚み・濃度）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category = "Cloud | Parameters", meta = (ClampMin = "0.1", ClampMax = "10.0"))
    float CloudDensity = 4.0f;

    // 雲の高度（高さ）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category = "Cloud | Parameters", meta = (ClampMin = "0.0", ClampMax = "10000.0"))
    float CloudHeight = 1000.0f;

    // 風向ベクトル (X, Y, Z)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category = "Cloud | Wind")
    FVector WindDirection = FVector(1.0f, 0.2f, 0.0f);

    // 風速
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category = "Cloud | Wind", meta = (ClampMin = "0.0", ClampMax = "500.0"))
    float WindSpeed = 50.0f;

    // 時刻パラメータ（0.0 〜 24.0 時間）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category = "Cloud | Environment", meta = (ClampMin = "0.0", ClampMax = "24.0"))
    float TimeOfDay = 12.0f;

    // ゲームプレイ中に時間を自動進行させるフラグ
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Environment")
    bool bAutoAdvanceTime = false;

    // 時間進行スピード（1.0 = 1秒で1時間進行）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Environment", meta = (EditCondition = "bAutoAdvanceTime"))
    float TimeSpeed = 0.1f;

    // -------------------------------------------------------------------------
    // 関数・ヘルパー
    // -------------------------------------------------------------------------

    int32 GetDebugModeAsInt() const { return static_cast<int32>(DebugMode); }

    // パラメータをMPCおよび太陽の角度・カラーへ反映させる関数
    UFUNCTION(BlueprintCallable, Category = "Cloud | Functions")
    void UpdateEnvironmentAndMPC();
};
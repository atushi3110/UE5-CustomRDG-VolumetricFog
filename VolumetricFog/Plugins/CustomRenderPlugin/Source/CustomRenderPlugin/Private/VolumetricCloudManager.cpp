// VolumetricCloudManager.cpp

#include "VolumetricCloudManager.h"
#include "Materials/MaterialParameterCollectionInstance.h"
#include "Kismet/KismetMathLibrary.h"

AVolumetricCloudManager::AVolumetricCloudManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AVolumetricCloudManager::BeginPlay()
{
    Super::BeginPlay();
    UpdateEnvironmentAndMPC();
}

void AVolumetricCloudManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 自動時間進行処理
    if (bAutoAdvanceTime)
    {
        TimeOfDay += DeltaTime * TimeSpeed;
        if (TimeOfDay >= 24.0f)
        {
            TimeOfDay = FMath::Fmod(TimeOfDay, 24.0f);
        }
    }

    // 毎フレーム環境とMPCを動的に更新
    UpdateEnvironmentAndMPC();
}

void AVolumetricCloudManager::UpdateEnvironmentAndMPC()
{
    // -------------------------------------------------------------------------
    // 1. 太陽の回転角度とカラーの連動計算
    // -------------------------------------------------------------------------

    // TimeOfDay (0~24h) を度数法 (0~360度) に変換 (6時=0度[日の出], 12時=90度[正午], 18時=180度[日没])
    float SunPitch = ((TimeOfDay - 6.0f) / 24.0f) * 360.0f;
    FRotator SunRotation = FRotator(-SunPitch, 0.0f, 0.0f); // Pitchで太陽の昇り沈みを表現

    FVector CurrentLightDirection = SunRotation.Vector();
    FLinearColor CurrentLightColor = FLinearColor::White;

    // カラーカーブが割り当てられている場合は時刻に応じた色を取得
    if (SunColorCurve)
    {
        CurrentLightColor = SunColorCurve->GetLinearColorValue(TimeOfDay);
    }

    // 太陽 (Directional Light) のアクタが存在すれば設定を適用
    if (SunLight)
    {
        SunLight->SetActorRotation(SunRotation);

        if (UDirectionalLightComponent* LightComp = Cast<UDirectionalLightComponent>(SunLight->GetLightComponent()))
        {
            LightComp->SetLightColor(CurrentLightColor);
        }
    }

    // -------------------------------------------------------------------------
    // 2. Material Parameter Collection (MPC) の更新
    // -------------------------------------------------------------------------
    if (!FogMPC || !GetWorld()) return;

    UMaterialParameterCollectionInstance* MPCInstance = GetWorld()->GetParameterCollectionInstance(FogMPC);
    if (!MPCInstance) return;

    // Scalar Parameters
    MPCInstance->SetScalarParameterValue(FName("CloudCoverage"), CloudCoverage);
    MPCInstance->SetScalarParameterValue(FName("CloudDensity"), CloudDensity);
    MPCInstance->SetScalarParameterValue(FName("CloudHeight"), CloudHeight);
    MPCInstance->SetScalarParameterValue(FName("WindSpeed"), WindSpeed);
    MPCInstance->SetScalarParameterValue(FName("TimeOfDay"), TimeOfDay);
    MPCInstance->SetScalarParameterValue(FName("DebugMode"), static_cast<float>(GetDebugModeAsInt()));

    // Vector Parameters
    MPCInstance->SetVectorParameterValue(FName("CloudColor"), CloudColor);
    MPCInstance->SetVectorParameterValue(FName("WindDirection"), FLinearColor(WindDirection));
    MPCInstance->SetVectorParameterValue(FName("LightDirection"), FLinearColor(CurrentLightDirection));
    MPCInstance->SetVectorParameterValue(FName("LightColor"), CurrentLightColor);
}
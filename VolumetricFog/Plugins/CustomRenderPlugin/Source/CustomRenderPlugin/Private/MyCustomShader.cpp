#include "MyCustomShader.h"

// ★3. C++クラスと、実際のHLSLファイル（仮想パス）を完全に紐付けるマクロ
// 引数：( C++クラス名, "HLSLファイルの仮想パス", "HLSL内のメイン関数名", シェーダーステージ )
IMPLEMENT_GLOBAL_SHADER(
    FMyCustomPixelShader,
    "/Plugin/CustomRenderPlugin/Private/MyShader.usf", // ※後述のStep③でこのパスを設定します
    "MainPS",
    SF_Pixel
);
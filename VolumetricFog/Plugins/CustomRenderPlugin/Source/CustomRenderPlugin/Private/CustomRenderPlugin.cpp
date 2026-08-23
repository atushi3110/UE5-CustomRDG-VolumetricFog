// Copyright Epic Games, Inc. All Rights Reserved.

#include "CustomRenderPlugin.h" // ※ご自身のプラグイン名に合わせてください
#include "Interfaces/IPluginManager.h"
#include "ShaderCore.h"

#define LOCTEXT_NAMESPACE "FCustomRenderPluginModule"

void FCustomRenderPluginModule::StartupModule()
{
    // 1. プラグインの実際のインストールディレクトリ（ディスク上の絶対パス）を取得
    FString PluginShaderDir = FPaths::Combine(
        IPluginManager::Get().FindPlugin(TEXT("CustomRenderPlugin"))->GetBaseDir(), // ※プラグイン名
        TEXT("Shaders")
    );

    // 2. 仮想パス「/Plugin/CustomRenderPlugin」と実際のディレクトリを紐付ける
    // これにより、Step 2の IMPLEMENT_GLOBAL_SHADER で書いたパスが有効になります
    AddShaderSourceDirectoryMapping(TEXT("/Plugin/CustomRenderPlugin"), PluginShaderDir);
}

void FCustomRenderPluginModule::ShutdownModule()
{
    // エラーが出た行をコメントアウト、または削除します
        // ResetShaderSourceDirectoryMapping(); 

        // 代わりに以下の安全な方法でマッピングを解除するか、空のままでも検証は可能です
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomRenderPluginModule, CustomRenderPlugin)
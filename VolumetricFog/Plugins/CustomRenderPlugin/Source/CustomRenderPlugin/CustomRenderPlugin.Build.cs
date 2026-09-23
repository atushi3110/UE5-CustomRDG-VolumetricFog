// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CustomRenderPlugin : ModuleRules
{
	public CustomRenderPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "RenderCore", // RDG（Render Dependency Graph）やシェーダー管理に必須
				"RHI",        // 低レイヤーグラフィックスAPI（Render Hardware Interface）に必須
				"Projects"    // シェーダーのディレクトリマッピング（仮想パス登録）に必須
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomRenderPlugin_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_CustomRenderPlugin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_CustomRenderPlugin()
	{
		if (!Z_Registration_Info_UPackage__Script_CustomRenderPlugin.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/CustomRenderPlugin",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0xC7C97417,
			0x96AC4D6E,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_CustomRenderPlugin.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_CustomRenderPlugin.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_CustomRenderPlugin(Z_Construct_UPackage__Script_CustomRenderPlugin, TEXT("/Script/CustomRenderPlugin"), Z_Registration_Info_UPackage__Script_CustomRenderPlugin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xC7C97417, 0x96AC4D6E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

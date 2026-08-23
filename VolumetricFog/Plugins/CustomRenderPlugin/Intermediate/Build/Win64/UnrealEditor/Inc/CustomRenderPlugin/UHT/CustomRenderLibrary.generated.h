// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CustomRenderLibrary.h"

#ifdef CUSTOMRENDERPLUGIN_CustomRenderLibrary_generated_h
#error "CustomRenderLibrary.generated.h already included, missing '#pragma once' in CustomRenderLibrary.h"
#endif
#define CUSTOMRENDERPLUGIN_CustomRenderLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTextureRenderTarget2D;
struct FLinearColor;

// ********** Begin Class UCustomRenderLibrary *****************************************************
#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDrawCustomShaderToRenderTarget);


struct Z_Construct_UClass_UCustomRenderLibrary_Statics;
CUSTOMRENDERPLUGIN_API UClass* Z_Construct_UClass_UCustomRenderLibrary_NoRegister();

#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCustomRenderLibrary(); \
	friend struct ::Z_Construct_UClass_UCustomRenderLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CUSTOMRENDERPLUGIN_API UClass* ::Z_Construct_UClass_UCustomRenderLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UCustomRenderLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CustomRenderPlugin"), Z_Construct_UClass_UCustomRenderLibrary_NoRegister) \
	DECLARE_SERIALIZER(UCustomRenderLibrary)


#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomRenderLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCustomRenderLibrary(UCustomRenderLibrary&&) = delete; \
	UCustomRenderLibrary(const UCustomRenderLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomRenderLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomRenderLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCustomRenderLibrary) \
	NO_API virtual ~UCustomRenderLibrary();


#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h_8_PROLOG
#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h_11_INCLASS_NO_PURE_DECLS \
	FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCustomRenderLibrary;

// ********** End Class UCustomRenderLibrary *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyRenderTestLibrary.h"

#ifdef CUSTOMRENDERPLUGIN_MyRenderTestLibrary_generated_h
#error "MyRenderTestLibrary.generated.h already included, missing '#pragma once' in MyRenderTestLibrary.h"
#endif
#define CUSTOMRENDERPLUGIN_MyRenderTestLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTextureRenderTarget2D;
struct FLinearColor;

// ********** Begin Class UMyRenderTestLibrary *****************************************************
#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteCustomShader);


struct Z_Construct_UClass_UMyRenderTestLibrary_Statics;
CUSTOMRENDERPLUGIN_API UClass* Z_Construct_UClass_UMyRenderTestLibrary_NoRegister();

#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyRenderTestLibrary(); \
	friend struct ::Z_Construct_UClass_UMyRenderTestLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CUSTOMRENDERPLUGIN_API UClass* ::Z_Construct_UClass_UMyRenderTestLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UMyRenderTestLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CustomRenderPlugin"), Z_Construct_UClass_UMyRenderTestLibrary_NoRegister) \
	DECLARE_SERIALIZER(UMyRenderTestLibrary)


#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyRenderTestLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMyRenderTestLibrary(UMyRenderTestLibrary&&) = delete; \
	UMyRenderTestLibrary(const UMyRenderTestLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyRenderTestLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyRenderTestLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyRenderTestLibrary) \
	NO_API virtual ~UMyRenderTestLibrary();


#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h_8_PROLOG
#define FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h_11_INCLASS_NO_PURE_DECLS \
	FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMyRenderTestLibrary;

// ********** End Class UMyRenderTestLibrary *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

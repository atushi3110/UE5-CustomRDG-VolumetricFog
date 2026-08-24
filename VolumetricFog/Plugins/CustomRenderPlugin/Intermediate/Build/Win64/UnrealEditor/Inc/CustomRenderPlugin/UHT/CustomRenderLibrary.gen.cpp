// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomRenderLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCustomRenderLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FMatrix();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
CUSTOMRENDERPLUGIN_API UClass* Z_Construct_UClass_UCustomRenderLibrary();
CUSTOMRENDERPLUGIN_API UClass* Z_Construct_UClass_UCustomRenderLibrary_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_CustomRenderPlugin();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCustomRenderLibrary Function DrawCustomShaderToRenderTarget *************
struct Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics
{
	struct FMatrix
	{
		FPlane XPlane;
		FPlane YPlane;
		FPlane ZPlane;
		FPlane WPlane;
	};

	struct CustomRenderLibrary_eventDrawCustomShaderToRenderTarget_Parms
	{
		UTextureRenderTarget2D* OutputRenderTarget;
		FVector CameraPosition;
		FMatrix InvViewProjectionMatrix;
		float Time;
		FLinearColor Color;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CustomRender" },
		{ "ModuleRelativePath", "Public/CustomRenderLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DrawCustomShaderToRenderTarget constinit property declarations ********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OutputRenderTarget;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InvViewProjectionMatrix;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Time;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DrawCustomShaderToRenderTarget constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DrawCustomShaderToRenderTarget Property Definitions *******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_OutputRenderTarget = { "OutputRenderTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomRenderLibrary_eventDrawCustomShaderToRenderTarget_Parms, OutputRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_CameraPosition = { "CameraPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomRenderLibrary_eventDrawCustomShaderToRenderTarget_Parms, CameraPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_InvViewProjectionMatrix = { "InvViewProjectionMatrix", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomRenderLibrary_eventDrawCustomShaderToRenderTarget_Parms, InvViewProjectionMatrix), Z_Construct_UScriptStruct_FMatrix, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomRenderLibrary_eventDrawCustomShaderToRenderTarget_Parms, Time), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomRenderLibrary_eventDrawCustomShaderToRenderTarget_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_OutputRenderTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_CameraPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_InvViewProjectionMatrix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_Time,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::PropPointers) < 2048);
// ********** End Function DrawCustomShaderToRenderTarget Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCustomRenderLibrary, nullptr, "DrawCustomShaderToRenderTarget", 	Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::CustomRenderLibrary_eventDrawCustomShaderToRenderTarget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::CustomRenderLibrary_eventDrawCustomShaderToRenderTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomRenderLibrary::execDrawCustomShaderToRenderTarget)
{
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_OutputRenderTarget);
	P_GET_STRUCT(FVector,Z_Param_CameraPosition);
	P_GET_STRUCT(FMatrix,Z_Param_InvViewProjectionMatrix);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Time);
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	UCustomRenderLibrary::DrawCustomShaderToRenderTarget(Z_Param_OutputRenderTarget,Z_Param_CameraPosition,Z_Param_InvViewProjectionMatrix,Z_Param_Time,Z_Param_Color);
	P_NATIVE_END;
}
// ********** End Class UCustomRenderLibrary Function DrawCustomShaderToRenderTarget ***************

// ********** Begin Class UCustomRenderLibrary *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCustomRenderLibrary;
UClass* UCustomRenderLibrary::GetPrivateStaticClass()
{
	using TClass = UCustomRenderLibrary;
	if (!Z_Registration_Info_UClass_UCustomRenderLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CustomRenderLibrary"),
			Z_Registration_Info_UClass_UCustomRenderLibrary.InnerSingleton,
			StaticRegisterNativesUCustomRenderLibrary,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UCustomRenderLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UCustomRenderLibrary_NoRegister()
{
	return UCustomRenderLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCustomRenderLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CustomRenderLibrary.h" },
		{ "ModuleRelativePath", "Public/CustomRenderLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCustomRenderLibrary constinit property declarations *********************
// ********** End Class UCustomRenderLibrary constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("DrawCustomShaderToRenderTarget"), .Pointer = &UCustomRenderLibrary::execDrawCustomShaderToRenderTarget },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCustomRenderLibrary_DrawCustomShaderToRenderTarget, "DrawCustomShaderToRenderTarget" }, // 2416157319
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomRenderLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCustomRenderLibrary_Statics
UObject* (*const Z_Construct_UClass_UCustomRenderLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_CustomRenderPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomRenderLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCustomRenderLibrary_Statics::ClassParams = {
	&UCustomRenderLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomRenderLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UCustomRenderLibrary_Statics::Class_MetaDataParams)
};
void UCustomRenderLibrary::StaticRegisterNativesUCustomRenderLibrary()
{
	UClass* Class = UCustomRenderLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCustomRenderLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCustomRenderLibrary()
{
	if (!Z_Registration_Info_UClass_UCustomRenderLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomRenderLibrary.OuterSingleton, Z_Construct_UClass_UCustomRenderLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCustomRenderLibrary.OuterSingleton;
}
UCustomRenderLibrary::UCustomRenderLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCustomRenderLibrary);
UCustomRenderLibrary::~UCustomRenderLibrary() {}
// ********** End Class UCustomRenderLibrary *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h__Script_CustomRenderPlugin_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCustomRenderLibrary, UCustomRenderLibrary::StaticClass, TEXT("UCustomRenderLibrary"), &Z_Registration_Info_UClass_UCustomRenderLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomRenderLibrary), 286930527U) },
	};
}; // Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h__Script_CustomRenderPlugin_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h__Script_CustomRenderPlugin_219818734{
	TEXT("/Script/CustomRenderPlugin"),
	Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h__Script_CustomRenderPlugin_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Public_CustomRenderLibrary_h__Script_CustomRenderPlugin_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

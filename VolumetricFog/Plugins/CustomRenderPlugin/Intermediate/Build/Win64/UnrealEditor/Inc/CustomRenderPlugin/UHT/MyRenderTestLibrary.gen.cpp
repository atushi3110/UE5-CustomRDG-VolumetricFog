// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyRenderTestLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMyRenderTestLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
CUSTOMRENDERPLUGIN_API UClass* Z_Construct_UClass_UMyRenderTestLibrary();
CUSTOMRENDERPLUGIN_API UClass* Z_Construct_UClass_UMyRenderTestLibrary_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_CustomRenderPlugin();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UMyRenderTestLibrary Function ExecuteCustomShader ************************
struct Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics
{
	struct MyRenderTestLibrary_eventExecuteCustomShader_Parms
	{
		UTextureRenderTarget2D* RenderTarget;
		FLinearColor Color;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CustomRender" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbdu\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd[\xef\xbf\xbdv\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbdg\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc4\x82\xd1\x8fo\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc4\x81""A\xef\xbf\xbdw\xef\xbf\xbd\xe8\x82\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd_\xef\xbf\xbd[\xef\xbf\xbd^\xef\xbf\xbd[\xef\xbf\xbdQ\xef\xbf\xbd""b\xef\xbf\xbdg\xef\xbf\xbd\xef\xbf\xbd\xd4\x82\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xdf\x82\xef\xbf\xbd\xd6\x90\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Private/MyRenderTestLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbdu\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd[\xef\xbf\xbdv\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbdg\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc4\x82\xd1\x8fo\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc4\x81""A\xef\xbf\xbdw\xef\xbf\xbd\xe8\x82\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd_\xef\xbf\xbd[\xef\xbf\xbd^\xef\xbf\xbd[\xef\xbf\xbdQ\xef\xbf\xbd""b\xef\xbf\xbdg\xef\xbf\xbd\xef\xbf\xbd\xd4\x82\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xdf\x82\xef\xbf\xbd\xd6\x90\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteCustomShader constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteCustomShader constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteCustomShader Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::NewProp_RenderTarget = { "RenderTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyRenderTestLibrary_eventExecuteCustomShader_Parms, RenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyRenderTestLibrary_eventExecuteCustomShader_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::NewProp_RenderTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::PropPointers) < 2048);
// ********** End Function ExecuteCustomShader Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMyRenderTestLibrary, nullptr, "ExecuteCustomShader", 	Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::MyRenderTestLibrary_eventExecuteCustomShader_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::MyRenderTestLibrary_eventExecuteCustomShader_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyRenderTestLibrary::execExecuteCustomShader)
{
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_RenderTarget);
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMyRenderTestLibrary::ExecuteCustomShader(Z_Param_RenderTarget,Z_Param_Color);
	P_NATIVE_END;
}
// ********** End Class UMyRenderTestLibrary Function ExecuteCustomShader **************************

// ********** Begin Class UMyRenderTestLibrary *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UMyRenderTestLibrary;
UClass* UMyRenderTestLibrary::GetPrivateStaticClass()
{
	using TClass = UMyRenderTestLibrary;
	if (!Z_Registration_Info_UClass_UMyRenderTestLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MyRenderTestLibrary"),
			Z_Registration_Info_UClass_UMyRenderTestLibrary.InnerSingleton,
			StaticRegisterNativesUMyRenderTestLibrary,
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
	return Z_Registration_Info_UClass_UMyRenderTestLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UMyRenderTestLibrary_NoRegister()
{
	return UMyRenderTestLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UMyRenderTestLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyRenderTestLibrary.h" },
		{ "ModuleRelativePath", "Private/MyRenderTestLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMyRenderTestLibrary constinit property declarations *********************
// ********** End Class UMyRenderTestLibrary constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ExecuteCustomShader"), .Pointer = &UMyRenderTestLibrary::execExecuteCustomShader },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyRenderTestLibrary_ExecuteCustomShader, "ExecuteCustomShader" }, // 2892322043
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyRenderTestLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UMyRenderTestLibrary_Statics
UObject* (*const Z_Construct_UClass_UMyRenderTestLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_CustomRenderPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyRenderTestLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyRenderTestLibrary_Statics::ClassParams = {
	&UMyRenderTestLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyRenderTestLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyRenderTestLibrary_Statics::Class_MetaDataParams)
};
void UMyRenderTestLibrary::StaticRegisterNativesUMyRenderTestLibrary()
{
	UClass* Class = UMyRenderTestLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UMyRenderTestLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UMyRenderTestLibrary()
{
	if (!Z_Registration_Info_UClass_UMyRenderTestLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyRenderTestLibrary.OuterSingleton, Z_Construct_UClass_UMyRenderTestLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyRenderTestLibrary.OuterSingleton;
}
UMyRenderTestLibrary::UMyRenderTestLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMyRenderTestLibrary);
UMyRenderTestLibrary::~UMyRenderTestLibrary() {}
// ********** End Class UMyRenderTestLibrary *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h__Script_CustomRenderPlugin_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyRenderTestLibrary, UMyRenderTestLibrary::StaticClass, TEXT("UMyRenderTestLibrary"), &Z_Registration_Info_UClass_UMyRenderTestLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyRenderTestLibrary), 1308419752U) },
	};
}; // Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h__Script_CustomRenderPlugin_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h__Script_CustomRenderPlugin_4220049597{
	TEXT("/Script/CustomRenderPlugin"),
	Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h__Script_CustomRenderPlugin_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_Portfolio_UE5_CustomRDG_VolumetricFog_VolumetricFog_Plugins_CustomRenderPlugin_Source_CustomRenderPlugin_Private_MyRenderTestLibrary_h__Script_CustomRenderPlugin_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

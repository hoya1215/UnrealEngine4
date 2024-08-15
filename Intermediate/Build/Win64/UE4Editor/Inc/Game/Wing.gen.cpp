// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/Wing.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWing() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_AWing_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AWing();
	GAME_API UClass* Z_Construct_UClass_AClothes();
	UPackage* Z_Construct_UPackage__Script_Game();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AWing::StaticRegisterNativesAWing()
	{
	}
	UClass* Z_Construct_UClass_AWing_NoRegister()
	{
		return AWing::StaticClass();
	}
	struct Z_Construct_UClass_AWing_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWing_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AClothes,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWing_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Wing.h" },
		{ "ModuleRelativePath", "Wing.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWing_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Wing" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Wing.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWing_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWing, StaticMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWing_Statics::NewProp_StaticMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWing_Statics::NewProp_StaticMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWing_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWing_Statics::NewProp_StaticMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWing_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWing>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWing_Statics::ClassParams = {
		&AWing::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AWing_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AWing_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AWing_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWing_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWing()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWing_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWing, 2331905176);
	template<> GAME_API UClass* StaticClass<AWing>()
	{
		return AWing::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWing(Z_Construct_UClass_AWing, &AWing::StaticClass, TEXT("/Script/Game"), TEXT("AWing"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWing);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

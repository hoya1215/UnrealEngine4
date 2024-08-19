// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/Enemy_Boss.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemy_Boss() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_AEnemy_Boss_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AEnemy_Boss();
	GAME_API UClass* Z_Construct_UClass_AMyEnemy();
	UPackage* Z_Construct_UPackage__Script_Game();
	GAME_API UClass* Z_Construct_UClass_ARock_NoRegister();
// End Cross Module References
	void AEnemy_Boss::StaticRegisterNativesAEnemy_Boss()
	{
	}
	UClass* Z_Construct_UClass_AEnemy_Boss_NoRegister()
	{
		return AEnemy_Boss::StaticClass();
	}
	struct Z_Construct_UClass_AEnemy_Boss_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MyRock_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MyRock;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemy_Boss_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMyEnemy,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Boss_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Enemy_Boss.h" },
		{ "ModuleRelativePath", "Enemy_Boss.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Boss_Statics::NewProp_MyRock_MetaData[] = {
		{ "ModuleRelativePath", "Enemy_Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Boss_Statics::NewProp_MyRock = { "MyRock", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Boss, MyRock), Z_Construct_UClass_ARock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Boss_Statics::NewProp_MyRock_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Boss_Statics::NewProp_MyRock_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemy_Boss_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Boss_Statics::NewProp_MyRock,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemy_Boss_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemy_Boss>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemy_Boss_Statics::ClassParams = {
		&AEnemy_Boss::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEnemy_Boss_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Boss_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemy_Boss_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Boss_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemy_Boss()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemy_Boss_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemy_Boss, 32357709);
	template<> GAME_API UClass* StaticClass<AEnemy_Boss>()
	{
		return AEnemy_Boss::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemy_Boss(Z_Construct_UClass_AEnemy_Boss, &AEnemy_Boss::StaticClass, TEXT("/Script/Game"), TEXT("AEnemy_Boss"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemy_Boss);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

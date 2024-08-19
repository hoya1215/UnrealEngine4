// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/Enemy_Small.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemy_Small() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_AEnemy_Small_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AEnemy_Small();
	GAME_API UClass* Z_Construct_UClass_AMyEnemy();
	UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References
	void AEnemy_Small::StaticRegisterNativesAEnemy_Small()
	{
	}
	UClass* Z_Construct_UClass_AEnemy_Small_NoRegister()
	{
		return AEnemy_Small::StaticClass();
	}
	struct Z_Construct_UClass_AEnemy_Small_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemy_Small_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMyEnemy,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Small_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Enemy_Small.h" },
		{ "ModuleRelativePath", "Enemy_Small.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemy_Small_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemy_Small>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemy_Small_Statics::ClassParams = {
		&AEnemy_Small::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemy_Small_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Small_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemy_Small()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemy_Small_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemy_Small, 3638999613);
	template<> GAME_API UClass* StaticClass<AEnemy_Small>()
	{
		return AEnemy_Small::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemy_Small(Z_Construct_UClass_AEnemy_Small, &AEnemy_Small::StaticClass, TEXT("/Script/Game"), TEXT("AEnemy_Small"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemy_Small);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

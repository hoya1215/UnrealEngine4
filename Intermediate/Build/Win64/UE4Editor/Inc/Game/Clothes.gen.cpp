// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/Clothes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClothes() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_AClothes_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AClothes();
	GAME_API UClass* Z_Construct_UClass_AItem();
	UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References
	void AClothes::StaticRegisterNativesAClothes()
	{
	}
	UClass* Z_Construct_UClass_AClothes_NoRegister()
	{
		return AClothes::StaticClass();
	}
	struct Z_Construct_UClass_AClothes_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AClothes_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AItem,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AClothes_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Clothes.h" },
		{ "ModuleRelativePath", "Clothes.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AClothes_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AClothes>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AClothes_Statics::ClassParams = {
		&AClothes::StaticClass,
		"Engine",
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
		METADATA_PARAMS(Z_Construct_UClass_AClothes_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AClothes_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AClothes()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AClothes_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AClothes, 3022345194);
	template<> GAME_API UClass* StaticClass<AClothes>()
	{
		return AClothes::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AClothes(Z_Construct_UClass_AClothes, &AClothes::StaticClass, TEXT("/Script/Game"), TEXT("AClothes"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AClothes);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

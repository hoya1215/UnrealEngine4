// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/Sword.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSword() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_ASword_NoRegister();
	GAME_API UClass* Z_Construct_UClass_ASword();
	GAME_API UClass* Z_Construct_UClass_AWeapon();
	UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References
	void ASword::StaticRegisterNativesASword()
	{
	}
	UClass* Z_Construct_UClass_ASword_NoRegister()
	{
		return ASword::StaticClass();
	}
	struct Z_Construct_UClass_ASword_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASword_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWeapon,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASword_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Sword.h" },
		{ "ModuleRelativePath", "Sword.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASword_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASword>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASword_Statics::ClassParams = {
		&ASword::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASword_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASword_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASword()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASword_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASword, 4256631422);
	template<> GAME_API UClass* StaticClass<ASword>()
	{
		return ASword::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASword(Z_Construct_UClass_ASword, &ASword::StaticClass, TEXT("/Script/Game"), TEXT("ASword"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASword);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

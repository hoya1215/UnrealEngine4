// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/BTTask_PetAttack.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_PetAttack() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UBTTask_PetAttack_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UBTTask_PetAttack();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
	UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References
	void UBTTask_PetAttack::StaticRegisterNativesUBTTask_PetAttack()
	{
	}
	UClass* Z_Construct_UClass_UBTTask_PetAttack_NoRegister()
	{
		return UBTTask_PetAttack::StaticClass();
	}
	struct Z_Construct_UClass_UBTTask_PetAttack_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTTask_PetAttack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTTask_PetAttack_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BTTask_PetAttack.h" },
		{ "ModuleRelativePath", "BTTask_PetAttack.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTTask_PetAttack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_PetAttack>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_PetAttack_Statics::ClassParams = {
		&UBTTask_PetAttack::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UBTTask_PetAttack_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_PetAttack_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTTask_PetAttack()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBTTask_PetAttack_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBTTask_PetAttack, 3761353831);
	template<> GAME_API UClass* StaticClass<UBTTask_PetAttack>()
	{
		return UBTTask_PetAttack::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBTTask_PetAttack(Z_Construct_UClass_UBTTask_PetAttack, &UBTTask_PetAttack::StaticClass, TEXT("/Script/Game"), TEXT("UBTTask_PetAttack"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_PetAttack);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/BTService_CheckAttacking.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_CheckAttacking() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UBTService_CheckAttacking_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UBTService_CheckAttacking();
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References
	void UBTService_CheckAttacking::StaticRegisterNativesUBTService_CheckAttacking()
	{
	}
	UClass* Z_Construct_UClass_UBTService_CheckAttacking_NoRegister()
	{
		return UBTService_CheckAttacking::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_CheckAttacking_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_CheckAttacking_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_CheckAttacking_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BTService_CheckAttacking.h" },
		{ "ModuleRelativePath", "BTService_CheckAttacking.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_CheckAttacking_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_CheckAttacking>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBTService_CheckAttacking_Statics::ClassParams = {
		&UBTService_CheckAttacking::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UBTService_CheckAttacking_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_CheckAttacking_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTService_CheckAttacking()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBTService_CheckAttacking_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBTService_CheckAttacking, 3322778769);
	template<> GAME_API UClass* StaticClass<UBTService_CheckAttacking>()
	{
		return UBTService_CheckAttacking::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBTService_CheckAttacking(Z_Construct_UClass_UBTService_CheckAttacking, &UBTService_CheckAttacking::StaticClass, TEXT("/Script/Game"), TEXT("UBTService_CheckAttacking"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_CheckAttacking);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

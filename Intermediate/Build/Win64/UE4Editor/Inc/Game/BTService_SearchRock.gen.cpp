// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/BTService_SearchRock.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_SearchRock() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UBTService_SearchRock_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UBTService_SearchRock();
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References
	void UBTService_SearchRock::StaticRegisterNativesUBTService_SearchRock()
	{
	}
	UClass* Z_Construct_UClass_UBTService_SearchRock_NoRegister()
	{
		return UBTService_SearchRock::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_SearchRock_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_SearchRock_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_SearchRock_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BTService_SearchRock.h" },
		{ "ModuleRelativePath", "BTService_SearchRock.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_SearchRock_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_SearchRock>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBTService_SearchRock_Statics::ClassParams = {
		&UBTService_SearchRock::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UBTService_SearchRock_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_SearchRock_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTService_SearchRock()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBTService_SearchRock_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBTService_SearchRock, 3344272214);
	template<> GAME_API UClass* StaticClass<UBTService_SearchRock>()
	{
		return UBTService_SearchRock::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBTService_SearchRock(Z_Construct_UClass_UBTService_SearchRock, &UBTService_SearchRock::StaticClass, TEXT("/Script/Game"), TEXT("UBTService_SearchRock"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_SearchRock);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

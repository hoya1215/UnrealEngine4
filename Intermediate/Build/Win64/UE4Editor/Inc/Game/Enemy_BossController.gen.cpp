// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/Enemy_BossController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemy_BossController() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_AEnemy_BossController_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AEnemy_BossController();
	GAME_API UClass* Z_Construct_UClass_AEnemyController();
	UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References
	void AEnemy_BossController::StaticRegisterNativesAEnemy_BossController()
	{
	}
	UClass* Z_Construct_UClass_AEnemy_BossController_NoRegister()
	{
		return AEnemy_BossController::StaticClass();
	}
	struct Z_Construct_UClass_AEnemy_BossController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemy_BossController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemyController,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_BossController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Enemy_BossController.h" },
		{ "ModuleRelativePath", "Enemy_BossController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemy_BossController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemy_BossController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemy_BossController_Statics::ClassParams = {
		&AEnemy_BossController::StaticClass,
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
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemy_BossController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_BossController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemy_BossController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemy_BossController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemy_BossController, 739389486);
	template<> GAME_API UClass* StaticClass<AEnemy_BossController>()
	{
		return AEnemy_BossController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemy_BossController(Z_Construct_UClass_AEnemy_BossController, &AEnemy_BossController::StaticClass, TEXT("/Script/Game"), TEXT("AEnemy_BossController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemy_BossController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

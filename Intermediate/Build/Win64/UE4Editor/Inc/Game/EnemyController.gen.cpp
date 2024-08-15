// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/EnemyController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyController() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_AEnemyController_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AEnemyController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_Game();
	GAME_API UClass* Z_Construct_UClass_AMyCharacter_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
// End Cross Module References
	void AEnemyController::StaticRegisterNativesAEnemyController()
	{
	}
	UClass* Z_Construct_UClass_AEnemyController_NoRegister()
	{
		return AEnemyController::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MyCharacter_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MyCharacter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BlackboardData_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BlackboardData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BehaviorTree_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BehaviorTree;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "EnemyController.h" },
		{ "ModuleRelativePath", "EnemyController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyController_Statics::NewProp_MyCharacter_MetaData[] = {
		{ "ModuleRelativePath", "EnemyController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyController_Statics::NewProp_MyCharacter = { "MyCharacter", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyController, MyCharacter), Z_Construct_UClass_AMyCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemyController_Statics::NewProp_MyCharacter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyController_Statics::NewProp_MyCharacter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyController_Statics::NewProp_BlackboardData_MetaData[] = {
		{ "ModuleRelativePath", "EnemyController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyController_Statics::NewProp_BlackboardData = { "BlackboardData", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyController, BlackboardData), Z_Construct_UClass_UBlackboardData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemyController_Statics::NewProp_BlackboardData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyController_Statics::NewProp_BlackboardData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyController_Statics::NewProp_BehaviorTree_MetaData[] = {
		{ "ModuleRelativePath", "EnemyController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyController_Statics::NewProp_BehaviorTree = { "BehaviorTree", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyController, BehaviorTree), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemyController_Statics::NewProp_BehaviorTree_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyController_Statics::NewProp_BehaviorTree_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemyController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyController_Statics::NewProp_MyCharacter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyController_Statics::NewProp_BlackboardData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyController_Statics::NewProp_BehaviorTree,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyController_Statics::ClassParams = {
		&AEnemyController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEnemyController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemyController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyController, 1488895925);
	template<> GAME_API UClass* StaticClass<AEnemyController>()
	{
		return AEnemyController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyController(Z_Construct_UClass_AEnemyController, &AEnemyController::StaticClass, TEXT("/Script/Game"), TEXT("AEnemyController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

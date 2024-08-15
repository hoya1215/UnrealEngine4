// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/EnemyAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyAnimInstance() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UEnemyAnimInstance_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UEnemyAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_Game();
	GAME_API UClass* Z_Construct_UClass_AMyEnemy_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UEnemyAnimInstance::execAnimNotify_RockPick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimNotify_RockPick();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEnemyAnimInstance::execAnimNotify_AttackEnd)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimNotify_AttackEnd();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEnemyAnimInstance::execAnimNotify_AttackHit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimNotify_AttackHit();
		P_NATIVE_END;
	}
	void UEnemyAnimInstance::StaticRegisterNativesUEnemyAnimInstance()
	{
		UClass* Class = UEnemyAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AnimNotify_AttackEnd", &UEnemyAnimInstance::execAnimNotify_AttackEnd },
			{ "AnimNotify_AttackHit", &UEnemyAnimInstance::execAnimNotify_AttackHit },
			{ "AnimNotify_RockPick", &UEnemyAnimInstance::execAnimNotify_RockPick },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackEnd_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEnemyAnimInstance, nullptr, "AnimNotify_AttackEnd", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackHit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEnemyAnimInstance, nullptr, "AnimNotify_AttackHit", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackHit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_RockPick_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_RockPick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_RockPick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEnemyAnimInstance, nullptr, "AnimNotify_RockPick", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_RockPick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_RockPick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_RockPick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_RockPick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UEnemyAnimInstance_NoRegister()
	{
		return UEnemyAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UEnemyAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentEnemy_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurrentEnemy;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hp_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Hp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsPicking_MetaData[];
#endif
		static void NewProp_IsPicking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsPicking;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsAttack_MetaData[];
#endif
		static void NewProp_IsAttack_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsAttack;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsWalking_MetaData[];
#endif
		static void NewProp_IsWalking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsWalking;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsFalling_MetaData[];
#endif
		static void NewProp_IsFalling_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsFalling;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Speed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEnemyAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UEnemyAnimInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackEnd, "AnimNotify_AttackEnd" }, // 2704186360
		{ &Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_AttackHit, "AnimNotify_AttackHit" }, // 1031634204
		{ &Z_Construct_UFunction_UEnemyAnimInstance_AnimNotify_RockPick, "AnimNotify_RockPick" }, // 3852749033
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "EnemyAnimInstance.h" },
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_CurrentEnemy_MetaData[] = {
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_CurrentEnemy = { "CurrentEnemy", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEnemyAnimInstance, CurrentEnemy), Z_Construct_UClass_AMyEnemy_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_CurrentEnemy_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_CurrentEnemy_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Hp_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Hp = { "Hp", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEnemyAnimInstance, Hp), METADATA_PARAMS(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Hp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Hp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsPicking_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsPicking_SetBit(void* Obj)
	{
		((UEnemyAnimInstance*)Obj)->IsPicking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsPicking = { "IsPicking", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEnemyAnimInstance), &Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsPicking_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsPicking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsPicking_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsAttack_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsAttack_SetBit(void* Obj)
	{
		((UEnemyAnimInstance*)Obj)->IsAttack = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsAttack = { "IsAttack", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEnemyAnimInstance), &Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsAttack_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsAttack_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsWalking_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsWalking_SetBit(void* Obj)
	{
		((UEnemyAnimInstance*)Obj)->IsWalking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsWalking = { "IsWalking", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEnemyAnimInstance), &Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsWalking_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsWalking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsWalking_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsFalling_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsFalling_SetBit(void* Obj)
	{
		((UEnemyAnimInstance*)Obj)->IsFalling = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsFalling = { "IsFalling", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEnemyAnimInstance), &Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsFalling_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsFalling_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsFalling_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Speed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "EnemyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEnemyAnimInstance, Speed), METADATA_PARAMS(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Speed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEnemyAnimInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_CurrentEnemy,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Hp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsPicking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsAttack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsWalking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_IsFalling,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnimInstance_Statics::NewProp_Speed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEnemyAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEnemyAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UEnemyAnimInstance_Statics::ClassParams = {
		&UEnemyAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEnemyAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UEnemyAnimInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEnemyAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UEnemyAnimInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UEnemyAnimInstance, 1919043641);
	template<> GAME_API UClass* StaticClass<UEnemyAnimInstance>()
	{
		return UEnemyAnimInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UEnemyAnimInstance(Z_Construct_UClass_UEnemyAnimInstance, &UEnemyAnimInstance::StaticClass, TEXT("/Script/Game"), TEXT("UEnemyAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEnemyAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

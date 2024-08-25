// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/MyEnemy.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyEnemy() {}
// Cross Module References
	GAME_API UScriptStruct* Z_Construct_UScriptStruct_FEnemyInfo();
	UPackage* Z_Construct_UPackage__Script_Game();
	GAME_API UClass* Z_Construct_UClass_AMyEnemy_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AMyEnemy();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	GAME_API UClass* Z_Construct_UClass_UMyCharacterStatComponent_NoRegister();
	GAME_API UEnum* Z_Construct_UEnum_Game_EENEMY_TYPE();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UEnemyAnimInstance_NoRegister();
// End Cross Module References
class UScriptStruct* FEnemyInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern GAME_API uint32 Get_Z_Construct_UScriptStruct_FEnemyInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FEnemyInfo, Z_Construct_UPackage__Script_Game(), TEXT("EnemyInfo"), sizeof(FEnemyInfo), Get_Z_Construct_UScriptStruct_FEnemyInfo_Hash());
	}
	return Singleton;
}
template<> GAME_API UScriptStruct* StaticStruct<FEnemyInfo>()
{
	return FEnemyInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FEnemyInfo(FEnemyInfo::StaticStruct, TEXT("/Script/Game"), TEXT("EnemyInfo"), false, nullptr, nullptr);
static struct FScriptStruct_Game_StaticRegisterNativesFEnemyInfo
{
	FScriptStruct_Game_StaticRegisterNativesFEnemyInfo()
	{
		UScriptStruct::DeferCppStructOps<FEnemyInfo>(FName(TEXT("EnemyInfo")));
	}
} ScriptStruct_Game_StaticRegisterNativesFEnemyInfo;
	struct Z_Construct_UScriptStruct_FEnemyInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Power_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Power;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Speed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentHp_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_CurrentHp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyInfo_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEnemyInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Power_MetaData[] = {
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEnemyInfo, Power), METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Power_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Power_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Speed_MetaData[] = {
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEnemyInfo, Speed), METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Speed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_CurrentHp_MetaData[] = {
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_CurrentHp = { "CurrentHp", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEnemyInfo, CurrentHp), METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_CurrentHp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_CurrentHp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEnemyInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Power,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_Speed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEnemyInfo_Statics::NewProp_CurrentHp,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEnemyInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
		nullptr,
		&NewStructOps,
		"EnemyInfo",
		sizeof(FEnemyInfo),
		alignof(FEnemyInfo),
		Z_Construct_UScriptStruct_FEnemyInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FEnemyInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEnemyInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FEnemyInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FEnemyInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Game();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("EnemyInfo"), sizeof(FEnemyInfo), Get_Z_Construct_UScriptStruct_FEnemyInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FEnemyInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FEnemyInfo_Hash() { return 3259194869U; }
	void AMyEnemy::StaticRegisterNativesAMyEnemy()
	{
	}
	UClass* Z_Construct_UClass_AMyEnemy_NoRegister()
	{
		return AMyEnemy::StaticClass();
	}
	struct Z_Construct_UClass_AMyEnemy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotateRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RotateRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsZoom_MetaData[];
#endif
		static void NewProp_IsZoom_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsZoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Stat_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Stat;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsWalking_MetaData[];
#endif
		static void NewProp_IsWalking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsWalking;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsAttack_MetaData[];
#endif
		static void NewProp_IsAttack_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsAttack;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsPicking_MetaData[];
#endif
		static void NewProp_IsPicking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsPicking;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EnemyType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemyType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_EnemyType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackSound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DieSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DieSound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemyAnimInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EnemyAnimInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemyInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EnemyInfo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DefaultSpeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyEnemy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyEnemy.h" },
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_RotateRate_MetaData[] = {
		{ "Comment", "// Util\n" },
		{ "ModuleRelativePath", "MyEnemy.h" },
		{ "ToolTip", "Util" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_RotateRate = { "RotateRate", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyEnemy, RotateRate), METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_RotateRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_RotateRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsZoom_MetaData[] = {
		{ "Comment", "// Sensitivity\n" },
		{ "ModuleRelativePath", "MyEnemy.h" },
		{ "ToolTip", "Sensitivity" },
	};
#endif
	void Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsZoom_SetBit(void* Obj)
	{
		((AMyEnemy*)Obj)->IsZoom = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsZoom = { "IsZoom", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyEnemy), &Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsZoom_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsZoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsZoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_Stat_MetaData[] = {
		{ "Category", "MyEnemy" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_Stat = { "Stat", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyEnemy, Stat), Z_Construct_UClass_UMyCharacterStatComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_Stat_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_Stat_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsWalking_MetaData[] = {
		{ "Category", "MyEnemy" },
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	void Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsWalking_SetBit(void* Obj)
	{
		((AMyEnemy*)Obj)->IsWalking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsWalking = { "IsWalking", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyEnemy), &Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsWalking_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsWalking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsWalking_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsAttack_MetaData[] = {
		{ "Category", "MyEnemy" },
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	void Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsAttack_SetBit(void* Obj)
	{
		((AMyEnemy*)Obj)->IsAttack = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsAttack = { "IsAttack", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyEnemy), &Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsAttack_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsAttack_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsPicking_MetaData[] = {
		{ "Category", "MyEnemy" },
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	void Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsPicking_SetBit(void* Obj)
	{
		((AMyEnemy*)Obj)->IsPicking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsPicking = { "IsPicking", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyEnemy), &Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsPicking_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsPicking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsPicking_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyType_MetaData[] = {
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyType = { "EnemyType", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyEnemy, EnemyType), Z_Construct_UEnum_Game_EENEMY_TYPE, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_AttackSound_MetaData[] = {
		{ "Comment", "// Sound\n" },
		{ "ModuleRelativePath", "MyEnemy.h" },
		{ "ToolTip", "Sound" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_AttackSound = { "AttackSound", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyEnemy, AttackSound), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_AttackSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_AttackSound_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_DieSound_MetaData[] = {
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_DieSound = { "DieSound", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyEnemy, DieSound), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_DieSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_DieSound_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyAnimInstance_MetaData[] = {
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyAnimInstance = { "EnemyAnimInstance", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyEnemy, EnemyAnimInstance), Z_Construct_UClass_UEnemyAnimInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyAnimInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyAnimInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyInfo_MetaData[] = {
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyInfo = { "EnemyInfo", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyEnemy, EnemyInfo), Z_Construct_UScriptStruct_FEnemyInfo, METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyInfo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyEnemy_Statics::NewProp_DefaultSpeed_MetaData[] = {
		{ "ModuleRelativePath", "MyEnemy.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyEnemy_Statics::NewProp_DefaultSpeed = { "DefaultSpeed", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyEnemy, DefaultSpeed), METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::NewProp_DefaultSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::NewProp_DefaultSpeed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyEnemy_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_RotateRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsZoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_Stat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsWalking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsAttack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_IsPicking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_AttackSound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_DieSound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyAnimInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_EnemyInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyEnemy_Statics::NewProp_DefaultSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyEnemy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyEnemy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyEnemy_Statics::ClassParams = {
		&AMyEnemy::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMyEnemy_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyEnemy_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyEnemy()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyEnemy_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyEnemy, 2928172189);
	template<> GAME_API UClass* StaticClass<AMyEnemy>()
	{
		return AMyEnemy::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyEnemy(Z_Construct_UClass_AMyEnemy, &AMyEnemy::StaticClass, TEXT("/Script/Game"), TEXT("AMyEnemy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyEnemy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

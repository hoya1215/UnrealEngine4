// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/Pet.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePet() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_APet_NoRegister();
	GAME_API UClass* Z_Construct_UClass_APet();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Game();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AMyEnemy_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
// End Cross Module References
	void APet::StaticRegisterNativesAPet()
	{
	}
	UClass* Z_Construct_UClass_APet_NoRegister()
	{
		return APet::StaticClass();
	}
	struct Z_Construct_UClass_APet_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SkeletalMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SkeletalMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemyTarget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EnemyTarget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemyLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EnemyLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Power_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Power;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackArrange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AttackArrange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackEffectComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackEffectComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackEffect_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackEffect;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsAttacking_MetaData[];
#endif
		static void NewProp_bIsAttacking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsAttacking;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanAttack_MetaData[];
#endif
		static void NewProp_bCanAttack_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanAttack;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MagnetArrange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MagnetArrange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsMagnet_MetaData[];
#endif
		static void NewProp_bIsMagnet_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsMagnet;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APet_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Pet.h" },
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_SkeletalMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APet_Statics::NewProp_SkeletalMesh = { "SkeletalMesh", nullptr, (EPropertyFlags)0x0040000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APet, SkeletalMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_SkeletalMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_SkeletalMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_EnemyTarget_MetaData[] = {
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APet_Statics::NewProp_EnemyTarget = { "EnemyTarget", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APet, EnemyTarget), Z_Construct_UClass_AMyEnemy_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_EnemyTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_EnemyTarget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_EnemyLocation_MetaData[] = {
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_APet_Statics::NewProp_EnemyLocation = { "EnemyLocation", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APet, EnemyLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_EnemyLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_EnemyLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_Power_MetaData[] = {
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_APet_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APet, Power), METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_Power_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_Power_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_AttackArrange_MetaData[] = {
		{ "Comment", "// ???? ????\n" },
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APet_Statics::NewProp_AttackArrange = { "AttackArrange", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APet, AttackArrange), METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_AttackArrange_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_AttackArrange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_AttackEffectComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APet_Statics::NewProp_AttackEffectComponent = { "AttackEffectComponent", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APet, AttackEffectComponent), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_AttackEffectComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_AttackEffectComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_AttackEffect_MetaData[] = {
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APet_Statics::NewProp_AttackEffect = { "AttackEffect", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APet, AttackEffect), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_AttackEffect_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_AttackEffect_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_bIsAttacking_MetaData[] = {
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
	void Z_Construct_UClass_APet_Statics::NewProp_bIsAttacking_SetBit(void* Obj)
	{
		((APet*)Obj)->bIsAttacking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APet_Statics::NewProp_bIsAttacking = { "bIsAttacking", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(APet), &Z_Construct_UClass_APet_Statics::NewProp_bIsAttacking_SetBit, METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_bIsAttacking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_bIsAttacking_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_bCanAttack_MetaData[] = {
		{ "Comment", "// ???? \xc8\xbf??\n" },
		{ "ModuleRelativePath", "Pet.h" },
		{ "ToolTip", "???? \xc8\xbf??" },
	};
#endif
	void Z_Construct_UClass_APet_Statics::NewProp_bCanAttack_SetBit(void* Obj)
	{
		((APet*)Obj)->bCanAttack = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APet_Statics::NewProp_bCanAttack = { "bCanAttack", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(APet), &Z_Construct_UClass_APet_Statics::NewProp_bCanAttack_SetBit, METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_bCanAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_bCanAttack_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_MagnetArrange_MetaData[] = {
		{ "ModuleRelativePath", "Pet.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APet_Statics::NewProp_MagnetArrange = { "MagnetArrange", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APet, MagnetArrange), METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_MagnetArrange_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_MagnetArrange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APet_Statics::NewProp_bIsMagnet_MetaData[] = {
		{ "Comment", "// ?\xda\xbc? \xc8\xbf??\n" },
		{ "ModuleRelativePath", "Pet.h" },
		{ "ToolTip", "?\xda\xbc? \xc8\xbf??" },
	};
#endif
	void Z_Construct_UClass_APet_Statics::NewProp_bIsMagnet_SetBit(void* Obj)
	{
		((APet*)Obj)->bIsMagnet = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APet_Statics::NewProp_bIsMagnet = { "bIsMagnet", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(APet), &Z_Construct_UClass_APet_Statics::NewProp_bIsMagnet_SetBit, METADATA_PARAMS(Z_Construct_UClass_APet_Statics::NewProp_bIsMagnet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::NewProp_bIsMagnet_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APet_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_SkeletalMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_EnemyTarget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_EnemyLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_Power,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_AttackArrange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_AttackEffectComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_AttackEffect,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_bIsAttacking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_bCanAttack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_MagnetArrange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APet_Statics::NewProp_bIsMagnet,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APet_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APet>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APet_Statics::ClassParams = {
		&APet::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APet_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APet_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APet_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APet()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APet_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APet, 4251973832);
	template<> GAME_API UClass* StaticClass<APet>()
	{
		return APet::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APet(Z_Construct_UClass_APet, &APet::StaticClass, TEXT("/Script/Game"), TEXT("APet"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APet);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

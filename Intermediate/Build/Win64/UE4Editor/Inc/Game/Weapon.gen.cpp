// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/Weapon.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeapon() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_AWeapon_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AWeapon();
	GAME_API UClass* Z_Construct_UClass_AItem();
	UPackage* Z_Construct_UPackage__Script_Game();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
// End Cross Module References
	void AWeapon::StaticRegisterNativesAWeapon()
	{
	}
	UClass* Z_Construct_UClass_AWeapon_NoRegister()
	{
		return AWeapon::StaticClass();
	}
	struct Z_Construct_UClass_AWeapon_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponState_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_WeaponState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentBulletCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_CurrentBulletCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxBulletCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxBulletCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Effect_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Effect;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWeapon_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AItem,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeapon_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Weapon.h" },
		{ "ModuleRelativePath", "Weapon.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeapon_Statics::NewProp_WeaponState_MetaData[] = {
		{ "ModuleRelativePath", "Weapon.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWeapon_Statics::NewProp_WeaponState = { "WeaponState", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeapon, WeaponState), METADATA_PARAMS(Z_Construct_UClass_AWeapon_Statics::NewProp_WeaponState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeapon_Statics::NewProp_WeaponState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeapon_Statics::NewProp_CurrentBulletCount_MetaData[] = {
		{ "ModuleRelativePath", "Weapon.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWeapon_Statics::NewProp_CurrentBulletCount = { "CurrentBulletCount", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeapon, CurrentBulletCount), METADATA_PARAMS(Z_Construct_UClass_AWeapon_Statics::NewProp_CurrentBulletCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeapon_Statics::NewProp_CurrentBulletCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeapon_Statics::NewProp_MaxBulletCount_MetaData[] = {
		{ "ModuleRelativePath", "Weapon.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWeapon_Statics::NewProp_MaxBulletCount = { "MaxBulletCount", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeapon, MaxBulletCount), METADATA_PARAMS(Z_Construct_UClass_AWeapon_Statics::NewProp_MaxBulletCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeapon_Statics::NewProp_MaxBulletCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeapon_Statics::NewProp_Effect_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Weapon.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWeapon_Statics::NewProp_Effect = { "Effect", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeapon, Effect), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWeapon_Statics::NewProp_Effect_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeapon_Statics::NewProp_Effect_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWeapon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeapon_Statics::NewProp_WeaponState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeapon_Statics::NewProp_CurrentBulletCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeapon_Statics::NewProp_MaxBulletCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeapon_Statics::NewProp_Effect,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWeapon_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWeapon>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWeapon_Statics::ClassParams = {
		&AWeapon::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AWeapon_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AWeapon_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AWeapon_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWeapon_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWeapon()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWeapon_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWeapon, 3311338089);
	template<> GAME_API UClass* StaticClass<AWeapon>()
	{
		return AWeapon::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWeapon(Z_Construct_UClass_AWeapon, &AWeapon::StaticClass, TEXT("/Script/Game"), TEXT("AWeapon"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWeapon);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

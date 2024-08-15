// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/MyAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyAnimInstance() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UMyAnimInstance_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UMyAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_Game();
	GAME_API UClass* Z_Construct_UClass_AMyCharacter_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UMyAnimInstance::execAnimNotify_SwapEnd)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimNotify_SwapEnd();
		P_NATIVE_END;
	}
	void UMyAnimInstance::StaticRegisterNativesUMyAnimInstance()
	{
		UClass* Class = UMyAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AnimNotify_SwapEnd", &UMyAnimInstance::execAnimNotify_SwapEnd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMyAnimInstance_AnimNotify_SwapEnd_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyAnimInstance_AnimNotify_SwapEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyAnimInstance_AnimNotify_SwapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyAnimInstance, nullptr, "AnimNotify_SwapEnd", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyAnimInstance_AnimNotify_SwapEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyAnimInstance_AnimNotify_SwapEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyAnimInstance_AnimNotify_SwapEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyAnimInstance_AnimNotify_SwapEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMyAnimInstance_NoRegister()
	{
		return UMyAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UMyAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MyCharacter_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MyCharacter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hp_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Hp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentWeaponState_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_CurrentWeaponState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsAttacking_MetaData[];
#endif
		static void NewProp_IsAttacking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsAttacking;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsWeaponSwapping_MetaData[];
#endif
		static void NewProp_IsWeaponSwapping_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsWeaponSwapping;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsFlying_MetaData[];
#endif
		static void NewProp_IsFlying_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsFlying;
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
	UObject* (*const Z_Construct_UClass_UMyAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyAnimInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyAnimInstance_AnimNotify_SwapEnd, "AnimNotify_SwapEnd" }, // 1798045375
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "MyAnimInstance.h" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_MyCharacter_MetaData[] = {
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_MyCharacter = { "MyCharacter", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyAnimInstance, MyCharacter), Z_Construct_UClass_AMyCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_MyCharacter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_MyCharacter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Hp_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Hp = { "Hp", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyAnimInstance, Hp), METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Hp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Hp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_CurrentWeaponState_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_CurrentWeaponState = { "CurrentWeaponState", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyAnimInstance, CurrentWeaponState), METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_CurrentWeaponState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_CurrentWeaponState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsAttacking_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsAttacking_SetBit(void* Obj)
	{
		((UMyAnimInstance*)Obj)->IsAttacking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsAttacking = { "IsAttacking", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UMyAnimInstance), &Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsAttacking_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsAttacking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsAttacking_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWeaponSwapping_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWeaponSwapping_SetBit(void* Obj)
	{
		((UMyAnimInstance*)Obj)->IsWeaponSwapping = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWeaponSwapping = { "IsWeaponSwapping", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UMyAnimInstance), &Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWeaponSwapping_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWeaponSwapping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWeaponSwapping_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFlying_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFlying_SetBit(void* Obj)
	{
		((UMyAnimInstance*)Obj)->IsFlying = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFlying = { "IsFlying", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UMyAnimInstance), &Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFlying_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFlying_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFlying_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWalking_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWalking_SetBit(void* Obj)
	{
		((UMyAnimInstance*)Obj)->IsWalking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWalking = { "IsWalking", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UMyAnimInstance), &Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWalking_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWalking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWalking_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFalling_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFalling_SetBit(void* Obj)
	{
		((UMyAnimInstance*)Obj)->IsFalling = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFalling = { "IsFalling", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UMyAnimInstance), &Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFalling_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFalling_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFalling_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyAnimInstance, Speed), METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyAnimInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_MyCharacter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Hp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_CurrentWeaponState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsAttacking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWeaponSwapping,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsWalking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_IsFalling,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMyAnimInstance_Statics::ClassParams = {
		&UMyAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMyAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UMyAnimInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyAnimInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyAnimInstance, 2760195519);
	template<> GAME_API UClass* StaticClass<UMyAnimInstance>()
	{
		return UMyAnimInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyAnimInstance(Z_Construct_UClass_UMyAnimInstance, &UMyAnimInstance::StaticClass, TEXT("/Script/Game"), TEXT("UMyAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

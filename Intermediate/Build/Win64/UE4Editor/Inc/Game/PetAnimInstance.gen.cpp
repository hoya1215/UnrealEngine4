// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/PetAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePetAnimInstance() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UPetAnimInstance_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UPetAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_Game();
	GAME_API UClass* Z_Construct_UClass_APet_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UPetAnimInstance::execAnimNotify_AttackEnd)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimNotify_AttackEnd();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPetAnimInstance::execAnimNotify_Attack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimNotify_Attack();
		P_NATIVE_END;
	}
	void UPetAnimInstance::StaticRegisterNativesUPetAnimInstance()
	{
		UClass* Class = UPetAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AnimNotify_Attack", &UPetAnimInstance::execAnimNotify_Attack },
			{ "AnimNotify_AttackEnd", &UPetAnimInstance::execAnimNotify_AttackEnd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPetAnimInstance_AnimNotify_Attack_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPetAnimInstance_AnimNotify_Attack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PetAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPetAnimInstance_AnimNotify_Attack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPetAnimInstance, nullptr, "AnimNotify_Attack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPetAnimInstance_AnimNotify_Attack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPetAnimInstance_AnimNotify_Attack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPetAnimInstance_AnimNotify_Attack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPetAnimInstance_AnimNotify_Attack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPetAnimInstance_AnimNotify_AttackEnd_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPetAnimInstance_AnimNotify_AttackEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PetAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPetAnimInstance_AnimNotify_AttackEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPetAnimInstance, nullptr, "AnimNotify_AttackEnd", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPetAnimInstance_AnimNotify_AttackEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPetAnimInstance_AnimNotify_AttackEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPetAnimInstance_AnimNotify_AttackEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPetAnimInstance_AnimNotify_AttackEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPetAnimInstance_NoRegister()
	{
		return UPetAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UPetAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MyPet_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MyPet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsAttacking_MetaData[];
#endif
		static void NewProp_bIsAttacking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsAttacking;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPetAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPetAnimInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPetAnimInstance_AnimNotify_Attack, "AnimNotify_Attack" }, // 2272387194
		{ &Z_Construct_UFunction_UPetAnimInstance_AnimNotify_AttackEnd, "AnimNotify_AttackEnd" }, // 3927069706
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPetAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "PetAnimInstance.h" },
		{ "ModuleRelativePath", "PetAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_MyPet_MetaData[] = {
		{ "ModuleRelativePath", "PetAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_MyPet = { "MyPet", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPetAnimInstance, MyPet), Z_Construct_UClass_APet_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_MyPet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_MyPet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_bIsAttacking_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "PetAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_bIsAttacking_SetBit(void* Obj)
	{
		((UPetAnimInstance*)Obj)->bIsAttacking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_bIsAttacking = { "bIsAttacking", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPetAnimInstance), &Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_bIsAttacking_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_bIsAttacking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_bIsAttacking_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPetAnimInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_MyPet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPetAnimInstance_Statics::NewProp_bIsAttacking,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPetAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPetAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPetAnimInstance_Statics::ClassParams = {
		&UPetAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPetAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPetAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UPetAnimInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPetAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPetAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPetAnimInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPetAnimInstance, 3658525171);
	template<> GAME_API UClass* StaticClass<UPetAnimInstance>()
	{
		return UPetAnimInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPetAnimInstance(Z_Construct_UClass_UPetAnimInstance, &UPetAnimInstance::StaticClass, TEXT("/Script/Game"), TEXT("UPetAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPetAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

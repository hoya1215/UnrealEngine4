// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/InventorySlotDrag.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventorySlotDrag() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UInventorySlotDrag_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UInventorySlotDrag();
	UMG_API UClass* Z_Construct_UClass_UDragDropOperation();
	UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References
	void UInventorySlotDrag::StaticRegisterNativesUInventorySlotDrag()
	{
	}
	UClass* Z_Construct_UClass_UInventorySlotDrag_NoRegister()
	{
		return UInventorySlotDrag::StaticClass();
	}
	struct Z_Construct_UClass_UInventorySlotDrag_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SlotIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_SlotIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventorySlotDrag_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDragDropOperation,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotDrag_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "InventorySlotDrag.h" },
		{ "ModuleRelativePath", "InventorySlotDrag.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotDrag_Statics::NewProp_SlotIndex_MetaData[] = {
		{ "ModuleRelativePath", "InventorySlotDrag.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UInventorySlotDrag_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotDrag, SlotIndex), METADATA_PARAMS(Z_Construct_UClass_UInventorySlotDrag_Statics::NewProp_SlotIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotDrag_Statics::NewProp_SlotIndex_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventorySlotDrag_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotDrag_Statics::NewProp_SlotIndex,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventorySlotDrag_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySlotDrag>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventorySlotDrag_Statics::ClassParams = {
		&UInventorySlotDrag::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UInventorySlotDrag_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotDrag_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInventorySlotDrag_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotDrag_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventorySlotDrag()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventorySlotDrag_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventorySlotDrag, 1717102002);
	template<> GAME_API UClass* StaticClass<UInventorySlotDrag>()
	{
		return UInventorySlotDrag::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventorySlotDrag(Z_Construct_UClass_UInventorySlotDrag, &UInventorySlotDrag::StaticClass, TEXT("/Script/Game"), TEXT("UInventorySlotDrag"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventorySlotDrag);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/MyInventoryDragDropOperation.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyInventoryDragDropOperation() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UMyInventoryDragDropOperation_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UMyInventoryDragDropOperation();
	UMG_API UClass* Z_Construct_UClass_UDragDropOperation();
	UPackage* Z_Construct_UPackage__Script_Game();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	void UMyInventoryDragDropOperation::StaticRegisterNativesUMyInventoryDragDropOperation()
	{
	}
	UClass* Z_Construct_UClass_UMyInventoryDragDropOperation_NoRegister()
	{
		return UMyInventoryDragDropOperation::StaticClass();
	}
	struct Z_Construct_UClass_UMyInventoryDragDropOperation_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InventoryWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InventoryWidget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDragDropOperation,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MyInventoryDragDropOperation.h" },
		{ "ModuleRelativePath", "MyInventoryDragDropOperation.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::NewProp_InventoryWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInventoryDragDropOperation.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::NewProp_InventoryWidget = { "InventoryWidget", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyInventoryDragDropOperation, InventoryWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::NewProp_InventoryWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::NewProp_InventoryWidget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::NewProp_InventoryWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyInventoryDragDropOperation>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::ClassParams = {
		&UMyInventoryDragDropOperation::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyInventoryDragDropOperation()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyInventoryDragDropOperation_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyInventoryDragDropOperation, 188115990);
	template<> GAME_API UClass* StaticClass<UMyInventoryDragDropOperation>()
	{
		return UMyInventoryDragDropOperation::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyInventoryDragDropOperation(Z_Construct_UClass_UMyInventoryDragDropOperation, &UMyInventoryDragDropOperation::StaticClass, TEXT("/Script/Game"), TEXT("UMyInventoryDragDropOperation"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyInventoryDragDropOperation);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

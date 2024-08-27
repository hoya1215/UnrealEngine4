// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/InventorySlotWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventorySlotWidget() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UInventorySlotWidget_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UInventorySlotWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_Game();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_USizeBox_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UInventoryWidget_NoRegister();
	GAME_API UClass* Z_Construct_UClass_AItem_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UMyGameInstance_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UInventorySlotWidget::execSetSizeBox)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Width);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Height);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSizeBox(Z_Param_Width,Z_Param_Height);
		P_NATIVE_END;
	}
	void UInventorySlotWidget::StaticRegisterNativesUInventorySlotWidget()
	{
		UClass* Class = UInventorySlotWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetSizeBox", &UInventorySlotWidget::execSetSizeBox },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics
	{
		struct InventorySlotWidget_eventSetSizeBox_Parms
		{
			float Width;
			float Height;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Width;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Height;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventorySlotWidget_eventSetSizeBox_Parms, Width), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventorySlotWidget_eventSetSizeBox_Parms, Height), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::NewProp_Width,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::NewProp_Height,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidget, nullptr, "SetSizeBox", nullptr, nullptr, sizeof(InventorySlotWidget_eventSetSizeBox_Parms), Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UInventorySlotWidget_NoRegister()
	{
		return UInventorySlotWidget::StaticClass();
	}
	struct Z_Construct_UClass_UInventorySlotWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SlotTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SlotTexture;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SlotImage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SlotImage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SlotText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SlotText;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SlotSizeBox_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SlotSizeBox;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Index_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Index;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Count_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Count;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InventoryWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InventoryWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurrentSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentItem_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurrentItem;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_ItemName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GameInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GameInstance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventorySlotWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInventorySlotWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventorySlotWidget_SetSizeBox, "SetSizeBox" }, // 3693941432
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "InventorySlotWidget.h" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotTexture_MetaData[] = {
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotTexture = { "SlotTexture", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, SlotTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotTexture_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotImage_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotImage = { "SlotImage", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, SlotImage), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotImage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotImage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotText = { "SlotText", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, SlotText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotText_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotSizeBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotSizeBox = { "SlotSizeBox", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, SlotSizeBox), Z_Construct_UClass_USizeBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotSizeBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotSizeBox_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Index_MetaData[] = {
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, Index), METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Index_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Index_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Count_MetaData[] = {
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, Count), METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Count_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Count_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_InventoryWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_InventoryWidget = { "InventoryWidget", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, InventoryWidget), Z_Construct_UClass_UInventoryWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_InventoryWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_InventoryWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentSlot_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentSlot = { "CurrentSlot", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, CurrentSlot), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentItem_MetaData[] = {
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentItem = { "CurrentItem", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, CurrentItem), Z_Construct_UClass_AItem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentItem_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemName_MetaData[] = {
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, ItemName), METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_GameInstance_MetaData[] = {
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_GameInstance = { "GameInstance", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, GameInstance), Z_Construct_UClass_UMyGameInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_GameInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_GameInstance_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotTexture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotImage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotText,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SlotSizeBox,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_Count,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_InventoryWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_CurrentItem,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_GameInstance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventorySlotWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySlotWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventorySlotWidget_Statics::ClassParams = {
		&UInventorySlotWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventorySlotWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventorySlotWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventorySlotWidget, 2834403369);
	template<> GAME_API UClass* StaticClass<UInventorySlotWidget>()
	{
		return UInventorySlotWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventorySlotWidget(Z_Construct_UClass_UInventorySlotWidget, &UInventorySlotWidget::StaticClass, TEXT("/Script/Game"), TEXT("UInventorySlotWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventorySlotWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

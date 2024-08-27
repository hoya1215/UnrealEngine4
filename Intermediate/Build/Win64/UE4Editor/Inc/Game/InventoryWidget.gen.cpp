// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/InventoryWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryWidget() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UInventoryWidget_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UInventoryWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_Game();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UInventorySlotWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UMyGameInstance_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UInventoryWidget::execClickEtcButton)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClickEtcButton();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryWidget::execClickConsumptionButton)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClickConsumptionButton();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryWidget::execClickEquipmentButton)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClickEquipmentButton();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryWidget::execAddItemToInventory)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_Name);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddItemToInventory(Z_Param_Name);
		P_NATIVE_END;
	}
	void UInventoryWidget::StaticRegisterNativesUInventoryWidget()
	{
		UClass* Class = UInventoryWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddItemToInventory", &UInventoryWidget::execAddItemToInventory },
			{ "ClickConsumptionButton", &UInventoryWidget::execClickConsumptionButton },
			{ "ClickEquipmentButton", &UInventoryWidget::execClickEquipmentButton },
			{ "ClickEtcButton", &UInventoryWidget::execClickEtcButton },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics
	{
		struct InventoryWidget_eventAddItemToInventory_Parms
		{
			FName Name;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Name;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryWidget_eventAddItemToInventory_Parms, Name), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::NewProp_Name,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryWidget, nullptr, "AddItemToInventory", nullptr, nullptr, sizeof(InventoryWidget_eventAddItemToInventory_Parms), Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryWidget_AddItemToInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryWidget_AddItemToInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryWidget_ClickConsumptionButton_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryWidget_ClickConsumptionButton_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidget_ClickConsumptionButton_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryWidget, nullptr, "ClickConsumptionButton", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryWidget_ClickConsumptionButton_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidget_ClickConsumptionButton_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryWidget_ClickConsumptionButton()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryWidget_ClickConsumptionButton_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryWidget_ClickEquipmentButton_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryWidget_ClickEquipmentButton_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidget_ClickEquipmentButton_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryWidget, nullptr, "ClickEquipmentButton", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryWidget_ClickEquipmentButton_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidget_ClickEquipmentButton_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryWidget_ClickEquipmentButton()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryWidget_ClickEquipmentButton_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryWidget_ClickEtcButton_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryWidget_ClickEtcButton_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidget_ClickEtcButton_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryWidget, nullptr, "ClickEtcButton", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryWidget_ClickEtcButton_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidget_ClickEtcButton_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryWidget_ClickEtcButton()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryWidget_ClickEtcButton_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UInventoryWidget_NoRegister()
	{
		return UInventoryWidget::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultSlotTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DefaultSlotTexture;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DefaultSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentMoney_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CurrentMoney;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MoneyAmount_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MoneyAmount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InventorySlotWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_InventorySlotWidgetClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EquipmentButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EquipmentButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConsumptionButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConsumptionButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EtcButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EtcButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot0_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot0;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot1_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot2_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot3_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot3;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot4_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot4;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot5_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot5;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot6_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot6;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot7_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot7;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot8_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot8;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot9_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot9;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot10_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot10;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Slot11_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Slot11;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GameInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GameInstance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInventoryWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryWidget_AddItemToInventory, "AddItemToInventory" }, // 1232440577
		{ &Z_Construct_UFunction_UInventoryWidget_ClickConsumptionButton, "ClickConsumptionButton" }, // 2914130504
		{ &Z_Construct_UFunction_UInventoryWidget_ClickEquipmentButton, "ClickEquipmentButton" }, // 3292781517
		{ &Z_Construct_UFunction_UInventoryWidget_ClickEtcButton, "ClickEtcButton" }, // 2675635457
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InventoryWidget.h" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlotTexture_MetaData[] = {
		{ "Category", "Texture" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlotTexture = { "DefaultSlotTexture", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, DefaultSlotTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlotTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlotTexture_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlot_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlot = { "DefaultSlot", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, DefaultSlot), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_CurrentMoney_MetaData[] = {
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_CurrentMoney = { "CurrentMoney", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, CurrentMoney), METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_CurrentMoney_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_CurrentMoney_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_MoneyAmount_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_MoneyAmount = { "MoneyAmount", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, MoneyAmount), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_MoneyAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_MoneyAmount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_InventorySlotWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "Comment", "//UPROPERTY(meta = (BindWidget))\n//USizeBox* InventorySizeBox;\n" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
		{ "ToolTip", "UPROPERTY(meta = (BindWidget))\nUSizeBox* InventorySizeBox;" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_InventorySlotWidgetClass = { "InventorySlotWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, InventorySlotWidgetClass), Z_Construct_UClass_UInventorySlotWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_InventorySlotWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_InventorySlotWidgetClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EquipmentButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EquipmentButton = { "EquipmentButton", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, EquipmentButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EquipmentButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EquipmentButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_ConsumptionButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_ConsumptionButton = { "ConsumptionButton", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, ConsumptionButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_ConsumptionButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_ConsumptionButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EtcButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EtcButton = { "EtcButton", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, EtcButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EtcButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EtcButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot0_MetaData[] = {
		{ "BindWidget", "" },
		{ "Comment", "// Slots\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
		{ "ToolTip", "Slots" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot0 = { "Slot0", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot0), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot0_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot0_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot1_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot1 = { "Slot1", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot1), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot2_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot2 = { "Slot2", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot2), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot3_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot3 = { "Slot3", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot3), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot3_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot3_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot4_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot4 = { "Slot4", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot4), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot4_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot4_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot5_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot5 = { "Slot5", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot5), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot5_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot5_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot6_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot6 = { "Slot6", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot6), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot6_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot6_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot7_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot7 = { "Slot7", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot7), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot7_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot7_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot8_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot8 = { "Slot8", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot8), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot8_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot8_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot9_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot9 = { "Slot9", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot9), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot9_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot9_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot10_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot10 = { "Slot10", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot10), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot10_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot10_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot11_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot11 = { "Slot11", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, Slot11), Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot11_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot11_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryWidget_Statics::NewProp_GameInstance_MetaData[] = {
		{ "ModuleRelativePath", "InventoryWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidget_Statics::NewProp_GameInstance = { "GameInstance", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryWidget, GameInstance), Z_Construct_UClass_UMyGameInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_GameInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::NewProp_GameInstance_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlotTexture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_DefaultSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_CurrentMoney,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_MoneyAmount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_InventorySlotWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EquipmentButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_ConsumptionButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_EtcButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot0,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot3,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot4,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot5,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot6,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot7,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot8,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot9,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot10,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_Slot11,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidget_Statics::NewProp_GameInstance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventoryWidget_Statics::ClassParams = {
		&UInventoryWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UInventoryWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInventoryWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventoryWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventoryWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventoryWidget, 452825174);
	template<> GAME_API UClass* StaticClass<UInventoryWidget>()
	{
		return UInventoryWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventoryWidget(Z_Construct_UClass_UInventoryWidget, &UInventoryWidget::StaticClass, TEXT("/Script/Game"), TEXT("UInventoryWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

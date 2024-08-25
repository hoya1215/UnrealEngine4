// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/EquipmentWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEquipmentWidget() {}
// Cross Module References
	GAME_API UClass* Z_Construct_UClass_UEquipmentWidget_NoRegister();
	GAME_API UClass* Z_Construct_UClass_UEquipmentWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_Game();
	UMG_API UClass* Z_Construct_UClass_UUniformGridPanel_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	GAME_API UClass* Z_Construct_UClass_UEquipmentSlotWidget_NoRegister();
	GAME_API UEnum* Z_Construct_UEnum_Game_EEQUIPMENT_TYPE();
// End Cross Module References
	void UEquipmentWidget::StaticRegisterNativesUEquipmentWidget()
	{
	}
	UClass* Z_Construct_UClass_UEquipmentWidget_NoRegister()
	{
		return UEquipmentWidget::StaticClass();
	}
	struct Z_Construct_UClass_UEquipmentWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LeftPanel_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LeftPanel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RightPanel_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RightPanel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EquipmentSlotWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_EquipmentSlotWidgetClass;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EquipmentSlots_ValueProp;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EquipmentSlots_Key_KeyProp_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_EquipmentSlots_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EquipmentSlots_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_EquipmentSlots;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WingSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WingSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShoesSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShoesSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HeadSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HeadSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MainWeaponSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MainWeaponSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SubWeaponSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SubWeaponSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherWeaponSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherWeaponSlot;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEquipmentWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "EquipmentWidget.h" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_LeftPanel_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_LeftPanel = { "LeftPanel", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, LeftPanel), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_LeftPanel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_LeftPanel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_RightPanel_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_RightPanel = { "RightPanel", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, RightPanel), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_RightPanel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_RightPanel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlotWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlotWidgetClass = { "EquipmentSlotWidgetClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, EquipmentSlotWidgetClass), Z_Construct_UClass_UEquipmentSlotWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlotWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlotWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots_ValueProp = { "EquipmentSlots", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UEquipmentSlotWidget_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots_Key_KeyProp = { "EquipmentSlots_Key", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Game_EEQUIPMENT_TYPE, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots = { "EquipmentSlots", nullptr, (EPropertyFlags)0x0010008000000008, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, EquipmentSlots), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_WingSlot_MetaData[] = {
		{ "BindWidget", "" },
		{ "Comment", "// ????\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_WingSlot = { "WingSlot", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, WingSlot), Z_Construct_UClass_UEquipmentSlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_WingSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_WingSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_ShoesSlot_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_ShoesSlot = { "ShoesSlot", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, ShoesSlot), Z_Construct_UClass_UEquipmentSlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_ShoesSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_ShoesSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_HeadSlot_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_HeadSlot = { "HeadSlot", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, HeadSlot), Z_Construct_UClass_UEquipmentSlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_HeadSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_HeadSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_MainWeaponSlot_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_MainWeaponSlot = { "MainWeaponSlot", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, MainWeaponSlot), Z_Construct_UClass_UEquipmentSlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_MainWeaponSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_MainWeaponSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_SubWeaponSlot_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_SubWeaponSlot = { "SubWeaponSlot", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, SubWeaponSlot), Z_Construct_UClass_UEquipmentSlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_SubWeaponSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_SubWeaponSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_OtherWeaponSlot_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EquipmentWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_OtherWeaponSlot = { "OtherWeaponSlot", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentWidget, OtherWeaponSlot), Z_Construct_UClass_UEquipmentSlotWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_OtherWeaponSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_OtherWeaponSlot_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEquipmentWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_LeftPanel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_RightPanel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlotWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots_Key_KeyProp_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_EquipmentSlots,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_WingSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_ShoesSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_HeadSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_MainWeaponSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_SubWeaponSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentWidget_Statics::NewProp_OtherWeaponSlot,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEquipmentWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEquipmentWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UEquipmentWidget_Statics::ClassParams = {
		&UEquipmentWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UEquipmentWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UEquipmentWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEquipmentWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UEquipmentWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UEquipmentWidget, 1501995416);
	template<> GAME_API UClass* StaticClass<UEquipmentWidget>()
	{
		return UEquipmentWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UEquipmentWidget(Z_Construct_UClass_UEquipmentWidget, &UEquipmentWidget::StaticClass, TEXT("/Script/Game"), TEXT("UEquipmentWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEquipmentWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

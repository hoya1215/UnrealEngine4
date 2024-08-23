// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_InventoryWidget_generated_h
#error "InventoryWidget.generated.h already included, missing '#pragma once' in InventoryWidget.h"
#endif
#define GAME_InventoryWidget_generated_h

#define GameCopy_Source_Game_InventoryWidget_h_23_SPARSE_DATA
#define GameCopy_Source_Game_InventoryWidget_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execClickEtcButton); \
	DECLARE_FUNCTION(execClickConsumptionButton); \
	DECLARE_FUNCTION(execClickEquipmentButton); \
	DECLARE_FUNCTION(execAddItemToInventory);


#define GameCopy_Source_Game_InventoryWidget_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClickEtcButton); \
	DECLARE_FUNCTION(execClickConsumptionButton); \
	DECLARE_FUNCTION(execClickEquipmentButton); \
	DECLARE_FUNCTION(execAddItemToInventory);


#define GameCopy_Source_Game_InventoryWidget_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryWidget(); \
	friend struct Z_Construct_UClass_UInventoryWidget_Statics; \
public: \
	DECLARE_CLASS(UInventoryWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UInventoryWidget)


#define GameCopy_Source_Game_InventoryWidget_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUInventoryWidget(); \
	friend struct Z_Construct_UClass_UInventoryWidget_Statics; \
public: \
	DECLARE_CLASS(UInventoryWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UInventoryWidget)


#define GameCopy_Source_Game_InventoryWidget_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryWidget(UInventoryWidget&&); \
	NO_API UInventoryWidget(const UInventoryWidget&); \
public:


#define GameCopy_Source_Game_InventoryWidget_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryWidget(UInventoryWidget&&); \
	NO_API UInventoryWidget(const UInventoryWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryWidget)


#define GameCopy_Source_Game_InventoryWidget_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__InventoryBoard() { return STRUCT_OFFSET(UInventoryWidget, InventoryBoard); } \
	FORCEINLINE static uint32 __PPO__TopSizeBox() { return STRUCT_OFFSET(UInventoryWidget, TopSizeBox); } \
	FORCEINLINE static uint32 __PPO__InventorySizeBox() { return STRUCT_OFFSET(UInventoryWidget, InventorySizeBox); } \
	FORCEINLINE static uint32 __PPO__InventorySlotWidgetClass() { return STRUCT_OFFSET(UInventoryWidget, InventorySlotWidgetClass); } \
	FORCEINLINE static uint32 __PPO__EquipmentButton() { return STRUCT_OFFSET(UInventoryWidget, EquipmentButton); } \
	FORCEINLINE static uint32 __PPO__ConsumptionButton() { return STRUCT_OFFSET(UInventoryWidget, ConsumptionButton); } \
	FORCEINLINE static uint32 __PPO__EtcButton() { return STRUCT_OFFSET(UInventoryWidget, EtcButton); }


#define GameCopy_Source_Game_InventoryWidget_h_20_PROLOG
#define GameCopy_Source_Game_InventoryWidget_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_InventoryWidget_h_23_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_InventoryWidget_h_23_SPARSE_DATA \
	GameCopy_Source_Game_InventoryWidget_h_23_RPC_WRAPPERS \
	GameCopy_Source_Game_InventoryWidget_h_23_INCLASS \
	GameCopy_Source_Game_InventoryWidget_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_InventoryWidget_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_InventoryWidget_h_23_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_InventoryWidget_h_23_SPARSE_DATA \
	GameCopy_Source_Game_InventoryWidget_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_InventoryWidget_h_23_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_InventoryWidget_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class UInventoryWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_InventoryWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_EquipmentWidget_generated_h
#error "EquipmentWidget.generated.h already included, missing '#pragma once' in EquipmentWidget.h"
#endif
#define GAME_EquipmentWidget_generated_h

#define GameCopy_Source_Game_EquipmentWidget_h_23_SPARSE_DATA
#define GameCopy_Source_Game_EquipmentWidget_h_23_RPC_WRAPPERS
#define GameCopy_Source_Game_EquipmentWidget_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_Source_Game_EquipmentWidget_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEquipmentWidget(); \
	friend struct Z_Construct_UClass_UEquipmentWidget_Statics; \
public: \
	DECLARE_CLASS(UEquipmentWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UEquipmentWidget)


#define GameCopy_Source_Game_EquipmentWidget_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUEquipmentWidget(); \
	friend struct Z_Construct_UClass_UEquipmentWidget_Statics; \
public: \
	DECLARE_CLASS(UEquipmentWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UEquipmentWidget)


#define GameCopy_Source_Game_EquipmentWidget_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEquipmentWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEquipmentWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEquipmentWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEquipmentWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEquipmentWidget(UEquipmentWidget&&); \
	NO_API UEquipmentWidget(const UEquipmentWidget&); \
public:


#define GameCopy_Source_Game_EquipmentWidget_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEquipmentWidget(UEquipmentWidget&&); \
	NO_API UEquipmentWidget(const UEquipmentWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEquipmentWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEquipmentWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEquipmentWidget)


#define GameCopy_Source_Game_EquipmentWidget_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__WingSlot() { return STRUCT_OFFSET(UEquipmentWidget, WingSlot); } \
	FORCEINLINE static uint32 __PPO__ShoesSlot() { return STRUCT_OFFSET(UEquipmentWidget, ShoesSlot); } \
	FORCEINLINE static uint32 __PPO__HeadSlot() { return STRUCT_OFFSET(UEquipmentWidget, HeadSlot); } \
	FORCEINLINE static uint32 __PPO__MainWeaponSlot() { return STRUCT_OFFSET(UEquipmentWidget, MainWeaponSlot); } \
	FORCEINLINE static uint32 __PPO__SubWeaponSlot() { return STRUCT_OFFSET(UEquipmentWidget, SubWeaponSlot); } \
	FORCEINLINE static uint32 __PPO__OtherWeaponSlot() { return STRUCT_OFFSET(UEquipmentWidget, OtherWeaponSlot); }


#define GameCopy_Source_Game_EquipmentWidget_h_20_PROLOG
#define GameCopy_Source_Game_EquipmentWidget_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_EquipmentWidget_h_23_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_EquipmentWidget_h_23_SPARSE_DATA \
	GameCopy_Source_Game_EquipmentWidget_h_23_RPC_WRAPPERS \
	GameCopy_Source_Game_EquipmentWidget_h_23_INCLASS \
	GameCopy_Source_Game_EquipmentWidget_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_EquipmentWidget_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_EquipmentWidget_h_23_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_EquipmentWidget_h_23_SPARSE_DATA \
	GameCopy_Source_Game_EquipmentWidget_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_EquipmentWidget_h_23_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_EquipmentWidget_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class UEquipmentWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_EquipmentWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define GAME_MyCharacter_generated_h

#define GameCopy_4_27_Source_Game_MyCharacter_h_27_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSounds_Statics; \
	GAME_API static class UScriptStruct* StaticStruct();


template<> GAME_API UScriptStruct* StaticStruct<struct FSounds>();

#define GameCopy_4_27_Source_Game_MyCharacter_h_50_SPARSE_DATA
#define GameCopy_4_27_Source_Game_MyCharacter_h_50_RPC_WRAPPERS
#define GameCopy_4_27_Source_Game_MyCharacter_h_50_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_4_27_Source_Game_MyCharacter_h_50_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define GameCopy_4_27_Source_Game_MyCharacter_h_50_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define GameCopy_4_27_Source_Game_MyCharacter_h_50_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public:


#define GameCopy_4_27_Source_Game_MyCharacter_h_50_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter)


#define GameCopy_4_27_Source_Game_MyCharacter_h_50_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MyWeapon() { return STRUCT_OFFSET(AMyCharacter, MyWeapon); } \
	FORCEINLINE static uint32 __PPO__Magazine() { return STRUCT_OFFSET(AMyCharacter, Magazine); } \
	FORCEINLINE static uint32 __PPO__MaxBulletSize() { return STRUCT_OFFSET(AMyCharacter, MaxBulletSize); } \
	FORCEINLINE static uint32 __PPO__BulletIndex() { return STRUCT_OFFSET(AMyCharacter, BulletIndex); } \
	FORCEINLINE static uint32 __PPO__MyInventory() { return STRUCT_OFFSET(AMyCharacter, MyInventory); } \
	FORCEINLINE static uint32 __PPO__MyInventoryWidgetClass() { return STRUCT_OFFSET(AMyCharacter, MyInventoryWidgetClass); } \
	FORCEINLINE static uint32 __PPO__MyInventoryWidget() { return STRUCT_OFFSET(AMyCharacter, MyInventoryWidget); } \
	FORCEINLINE static uint32 __PPO__MyEquipmentWidgetClass() { return STRUCT_OFFSET(AMyCharacter, MyEquipmentWidgetClass); } \
	FORCEINLINE static uint32 __PPO__MyEquipmentWidget() { return STRUCT_OFFSET(AMyCharacter, MyEquipmentWidget); } \
	FORCEINLINE static uint32 __PPO__MyController() { return STRUCT_OFFSET(AMyCharacter, MyController); } \
	FORCEINLINE static uint32 __PPO__MyWingClass() { return STRUCT_OFFSET(AMyCharacter, MyWingClass); } \
	FORCEINLINE static uint32 __PPO__MyWing() { return STRUCT_OFFSET(AMyCharacter, MyWing); } \
	FORCEINLINE static uint32 __PPO__PetClass() { return STRUCT_OFFSET(AMyCharacter, PetClass); } \
	FORCEINLINE static uint32 __PPO__MyPet() { return STRUCT_OFFSET(AMyCharacter, MyPet); } \
	FORCEINLINE static uint32 __PPO__MouseTimerHandle() { return STRUCT_OFFSET(AMyCharacter, MouseTimerHandle); }


#define GameCopy_4_27_Source_Game_MyCharacter_h_47_PROLOG
#define GameCopy_4_27_Source_Game_MyCharacter_h_50_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_PRIVATE_PROPERTY_OFFSET \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_SPARSE_DATA \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_RPC_WRAPPERS \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_INCLASS \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_4_27_Source_Game_MyCharacter_h_50_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_PRIVATE_PROPERTY_OFFSET \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_SPARSE_DATA \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_INCLASS_NO_PURE_DECLS \
	GameCopy_4_27_Source_Game_MyCharacter_h_50_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_4_27_Source_Game_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

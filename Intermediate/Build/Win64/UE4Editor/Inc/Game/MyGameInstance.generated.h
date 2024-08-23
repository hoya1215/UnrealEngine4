// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_MyGameInstance_generated_h
#error "MyGameInstance.generated.h already included, missing '#pragma once' in MyGameInstance.h"
#endif
#define GAME_MyGameInstance_generated_h

#define GameCopy_Source_Game_MyGameInstance_h_60_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FItemData_Statics; \
	GAME_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> GAME_API UScriptStruct* StaticStruct<struct FItemData>();

#define GameCopy_Source_Game_MyGameInstance_h_45_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEnemyData_Statics; \
	GAME_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> GAME_API UScriptStruct* StaticStruct<struct FEnemyData>();

#define GameCopy_Source_Game_MyGameInstance_h_32_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWeaponData_Statics; \
	GAME_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> GAME_API UScriptStruct* StaticStruct<struct FWeaponData>();

#define GameCopy_Source_Game_MyGameInstance_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCharacterData_Statics; \
	GAME_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> GAME_API UScriptStruct* StaticStruct<struct FCharacterData>();

#define GameCopy_Source_Game_MyGameInstance_h_80_SPARSE_DATA
#define GameCopy_Source_Game_MyGameInstance_h_80_RPC_WRAPPERS
#define GameCopy_Source_Game_MyGameInstance_h_80_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_Source_Game_MyGameInstance_h_80_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyGameInstance(); \
	friend struct Z_Construct_UClass_UMyGameInstance_Statics; \
public: \
	DECLARE_CLASS(UMyGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UMyGameInstance)


#define GameCopy_Source_Game_MyGameInstance_h_80_INCLASS \
private: \
	static void StaticRegisterNativesUMyGameInstance(); \
	friend struct Z_Construct_UClass_UMyGameInstance_Statics; \
public: \
	DECLARE_CLASS(UMyGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UMyGameInstance)


#define GameCopy_Source_Game_MyGameInstance_h_80_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyGameInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyGameInstance(UMyGameInstance&&); \
	NO_API UMyGameInstance(const UMyGameInstance&); \
public:


#define GameCopy_Source_Game_MyGameInstance_h_80_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyGameInstance(UMyGameInstance&&); \
	NO_API UMyGameInstance(const UMyGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyGameInstance)


#define GameCopy_Source_Game_MyGameInstance_h_80_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MyStats() { return STRUCT_OFFSET(UMyGameInstance, MyStats); } \
	FORCEINLINE static uint32 __PPO__WeaponData() { return STRUCT_OFFSET(UMyGameInstance, WeaponData); } \
	FORCEINLINE static uint32 __PPO__EnemyData() { return STRUCT_OFFSET(UMyGameInstance, EnemyData); } \
	FORCEINLINE static uint32 __PPO__ItemData() { return STRUCT_OFFSET(UMyGameInstance, ItemData); }


#define GameCopy_Source_Game_MyGameInstance_h_77_PROLOG
#define GameCopy_Source_Game_MyGameInstance_h_80_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_MyGameInstance_h_80_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_MyGameInstance_h_80_SPARSE_DATA \
	GameCopy_Source_Game_MyGameInstance_h_80_RPC_WRAPPERS \
	GameCopy_Source_Game_MyGameInstance_h_80_INCLASS \
	GameCopy_Source_Game_MyGameInstance_h_80_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_MyGameInstance_h_80_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_MyGameInstance_h_80_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_MyGameInstance_h_80_SPARSE_DATA \
	GameCopy_Source_Game_MyGameInstance_h_80_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_MyGameInstance_h_80_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_MyGameInstance_h_80_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class UMyGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_MyGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

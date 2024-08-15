// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_EnemyAnimInstance_generated_h
#error "EnemyAnimInstance.generated.h already included, missing '#pragma once' in EnemyAnimInstance.h"
#endif
#define GAME_EnemyAnimInstance_generated_h

#define GameCopy_Source_Game_EnemyAnimInstance_h_19_SPARSE_DATA
#define GameCopy_Source_Game_EnemyAnimInstance_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAnimNotify_RockPick); \
	DECLARE_FUNCTION(execAnimNotify_AttackEnd); \
	DECLARE_FUNCTION(execAnimNotify_AttackHit);


#define GameCopy_Source_Game_EnemyAnimInstance_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAnimNotify_RockPick); \
	DECLARE_FUNCTION(execAnimNotify_AttackEnd); \
	DECLARE_FUNCTION(execAnimNotify_AttackHit);


#define GameCopy_Source_Game_EnemyAnimInstance_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEnemyAnimInstance(); \
	friend struct Z_Construct_UClass_UEnemyAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UEnemyAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UEnemyAnimInstance)


#define GameCopy_Source_Game_EnemyAnimInstance_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUEnemyAnimInstance(); \
	friend struct Z_Construct_UClass_UEnemyAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UEnemyAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UEnemyAnimInstance)


#define GameCopy_Source_Game_EnemyAnimInstance_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEnemyAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEnemyAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEnemyAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEnemyAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEnemyAnimInstance(UEnemyAnimInstance&&); \
	NO_API UEnemyAnimInstance(const UEnemyAnimInstance&); \
public:


#define GameCopy_Source_Game_EnemyAnimInstance_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEnemyAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEnemyAnimInstance(UEnemyAnimInstance&&); \
	NO_API UEnemyAnimInstance(const UEnemyAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEnemyAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEnemyAnimInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEnemyAnimInstance)


#define GameCopy_Source_Game_EnemyAnimInstance_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CurrentEnemy() { return STRUCT_OFFSET(UEnemyAnimInstance, CurrentEnemy); }


#define GameCopy_Source_Game_EnemyAnimInstance_h_16_PROLOG
#define GameCopy_Source_Game_EnemyAnimInstance_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_SPARSE_DATA \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_RPC_WRAPPERS \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_INCLASS \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_EnemyAnimInstance_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_SPARSE_DATA \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_EnemyAnimInstance_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class UEnemyAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_EnemyAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_MyEnemy_generated_h
#error "MyEnemy.generated.h already included, missing '#pragma once' in MyEnemy.h"
#endif
#define GAME_MyEnemy_generated_h

#define GameCopy_Source_Game_MyEnemy_h_13_SPARSE_DATA
#define GameCopy_Source_Game_MyEnemy_h_13_RPC_WRAPPERS
#define GameCopy_Source_Game_MyEnemy_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_Source_Game_MyEnemy_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyEnemy(); \
	friend struct Z_Construct_UClass_AMyEnemy_Statics; \
public: \
	DECLARE_CLASS(AMyEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AMyEnemy)


#define GameCopy_Source_Game_MyEnemy_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAMyEnemy(); \
	friend struct Z_Construct_UClass_AMyEnemy_Statics; \
public: \
	DECLARE_CLASS(AMyEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AMyEnemy)


#define GameCopy_Source_Game_MyEnemy_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyEnemy(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyEnemy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyEnemy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyEnemy(AMyEnemy&&); \
	NO_API AMyEnemy(const AMyEnemy&); \
public:


#define GameCopy_Source_Game_MyEnemy_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyEnemy(AMyEnemy&&); \
	NO_API AMyEnemy(const AMyEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyEnemy)


#define GameCopy_Source_Game_MyEnemy_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__EnemyAnimInstance() { return STRUCT_OFFSET(AMyEnemy, EnemyAnimInstance); }


#define GameCopy_Source_Game_MyEnemy_h_10_PROLOG
#define GameCopy_Source_Game_MyEnemy_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_MyEnemy_h_13_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_MyEnemy_h_13_SPARSE_DATA \
	GameCopy_Source_Game_MyEnemy_h_13_RPC_WRAPPERS \
	GameCopy_Source_Game_MyEnemy_h_13_INCLASS \
	GameCopy_Source_Game_MyEnemy_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_MyEnemy_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_MyEnemy_h_13_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_MyEnemy_h_13_SPARSE_DATA \
	GameCopy_Source_Game_MyEnemy_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_MyEnemy_h_13_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_MyEnemy_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AMyEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_MyEnemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

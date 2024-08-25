// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_GameCharacter_generated_h
#error "GameCharacter.generated.h already included, missing '#pragma once' in GameCharacter.h"
#endif
#define GAME_GameCharacter_generated_h

#define GameCopy_4_27_Source_Game_GameCharacter_h_12_SPARSE_DATA
#define GameCopy_4_27_Source_Game_GameCharacter_h_12_RPC_WRAPPERS
#define GameCopy_4_27_Source_Game_GameCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_4_27_Source_Game_GameCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameCharacter(); \
	friend struct Z_Construct_UClass_AGameCharacter_Statics; \
public: \
	DECLARE_CLASS(AGameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AGameCharacter)


#define GameCopy_4_27_Source_Game_GameCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAGameCharacter(); \
	friend struct Z_Construct_UClass_AGameCharacter_Statics; \
public: \
	DECLARE_CLASS(AGameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AGameCharacter)


#define GameCopy_4_27_Source_Game_GameCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameCharacter(AGameCharacter&&); \
	NO_API AGameCharacter(const AGameCharacter&); \
public:


#define GameCopy_4_27_Source_Game_GameCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameCharacter(AGameCharacter&&); \
	NO_API AGameCharacter(const AGameCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameCharacter)


#define GameCopy_4_27_Source_Game_GameCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AGameCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AGameCharacter, FollowCamera); }


#define GameCopy_4_27_Source_Game_GameCharacter_h_9_PROLOG
#define GameCopy_4_27_Source_Game_GameCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_SPARSE_DATA \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_RPC_WRAPPERS \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_INCLASS \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_4_27_Source_Game_GameCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_SPARSE_DATA \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_INCLASS_NO_PURE_DECLS \
	GameCopy_4_27_Source_Game_GameCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AGameCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_4_27_Source_Game_GameCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

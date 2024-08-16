// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_MyGameModeBase_generated_h
#error "MyGameModeBase.generated.h already included, missing '#pragma once' in MyGameModeBase.h"
#endif
#define GAME_MyGameModeBase_generated_h

#define GameCopy_Source_Game_MyGameModeBase_h_27_SPARSE_DATA
#define GameCopy_Source_Game_MyGameModeBase_h_27_RPC_WRAPPERS
#define GameCopy_Source_Game_MyGameModeBase_h_27_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_Source_Game_MyGameModeBase_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyGameModeBase(); \
	friend struct Z_Construct_UClass_AMyGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AMyGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AMyGameModeBase)


#define GameCopy_Source_Game_MyGameModeBase_h_27_INCLASS \
private: \
	static void StaticRegisterNativesAMyGameModeBase(); \
	friend struct Z_Construct_UClass_AMyGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AMyGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AMyGameModeBase)


#define GameCopy_Source_Game_MyGameModeBase_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyGameModeBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyGameModeBase(AMyGameModeBase&&); \
	NO_API AMyGameModeBase(const AMyGameModeBase&); \
public:


#define GameCopy_Source_Game_MyGameModeBase_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyGameModeBase(AMyGameModeBase&&); \
	NO_API AMyGameModeBase(const AMyGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyGameModeBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyGameModeBase)


#define GameCopy_Source_Game_MyGameModeBase_h_27_PRIVATE_PROPERTY_OFFSET
#define GameCopy_Source_Game_MyGameModeBase_h_24_PROLOG
#define GameCopy_Source_Game_MyGameModeBase_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_MyGameModeBase_h_27_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_MyGameModeBase_h_27_SPARSE_DATA \
	GameCopy_Source_Game_MyGameModeBase_h_27_RPC_WRAPPERS \
	GameCopy_Source_Game_MyGameModeBase_h_27_INCLASS \
	GameCopy_Source_Game_MyGameModeBase_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_MyGameModeBase_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_MyGameModeBase_h_27_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_MyGameModeBase_h_27_SPARSE_DATA \
	GameCopy_Source_Game_MyGameModeBase_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_MyGameModeBase_h_27_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_MyGameModeBase_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AMyGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_MyGameModeBase_h


#define FOREACH_ENUM_EENEMY_TYPE(op) \
	op(EENEMY_TYPE::ET_DEFAULT) \
	op(EENEMY_TYPE::ET_SMALL) \
	op(EENEMY_TYPE::ET_BOSS) 

enum class EENEMY_TYPE : uint8;
template<> GAME_API UEnum* StaticEnum<EENEMY_TYPE>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS

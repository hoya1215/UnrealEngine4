// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_Money_generated_h
#error "Money.generated.h already included, missing '#pragma once' in Money.h"
#endif
#define GAME_Money_generated_h

#define GameCopy_Source_Game_Money_h_15_SPARSE_DATA
#define GameCopy_Source_Game_Money_h_15_RPC_WRAPPERS
#define GameCopy_Source_Game_Money_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_Source_Game_Money_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMoney(); \
	friend struct Z_Construct_UClass_AMoney_Statics; \
public: \
	DECLARE_CLASS(AMoney, AItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AMoney)


#define GameCopy_Source_Game_Money_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMoney(); \
	friend struct Z_Construct_UClass_AMoney_Statics; \
public: \
	DECLARE_CLASS(AMoney, AItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AMoney)


#define GameCopy_Source_Game_Money_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMoney(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMoney) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMoney); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMoney); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMoney(AMoney&&); \
	NO_API AMoney(const AMoney&); \
public:


#define GameCopy_Source_Game_Money_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMoney(AMoney&&); \
	NO_API AMoney(const AMoney&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMoney); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMoney); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMoney)


#define GameCopy_Source_Game_Money_h_15_PRIVATE_PROPERTY_OFFSET
#define GameCopy_Source_Game_Money_h_12_PROLOG
#define GameCopy_Source_Game_Money_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_Money_h_15_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_Money_h_15_SPARSE_DATA \
	GameCopy_Source_Game_Money_h_15_RPC_WRAPPERS \
	GameCopy_Source_Game_Money_h_15_INCLASS \
	GameCopy_Source_Game_Money_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_Money_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_Money_h_15_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_Money_h_15_SPARSE_DATA \
	GameCopy_Source_Game_Money_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_Money_h_15_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_Money_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AMoney>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_Money_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

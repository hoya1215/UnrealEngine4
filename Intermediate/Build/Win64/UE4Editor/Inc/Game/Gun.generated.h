// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_Gun_generated_h
#error "Gun.generated.h already included, missing '#pragma once' in Gun.h"
#endif
#define GAME_Gun_generated_h

#define GameCopy_Source_Game_Gun_h_14_SPARSE_DATA
#define GameCopy_Source_Game_Gun_h_14_RPC_WRAPPERS
#define GameCopy_Source_Game_Gun_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_Source_Game_Gun_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGun(); \
	friend struct Z_Construct_UClass_AGun_Statics; \
public: \
	DECLARE_CLASS(AGun, AWeapon, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AGun)


#define GameCopy_Source_Game_Gun_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAGun(); \
	friend struct Z_Construct_UClass_AGun_Statics; \
public: \
	DECLARE_CLASS(AGun, AWeapon, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AGun)


#define GameCopy_Source_Game_Gun_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGun(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGun) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGun); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGun); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGun(AGun&&); \
	NO_API AGun(const AGun&); \
public:


#define GameCopy_Source_Game_Gun_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGun(AGun&&); \
	NO_API AGun(const AGun&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGun); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGun); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGun)


#define GameCopy_Source_Game_Gun_h_14_PRIVATE_PROPERTY_OFFSET
#define GameCopy_Source_Game_Gun_h_11_PROLOG
#define GameCopy_Source_Game_Gun_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_Gun_h_14_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_Gun_h_14_SPARSE_DATA \
	GameCopy_Source_Game_Gun_h_14_RPC_WRAPPERS \
	GameCopy_Source_Game_Gun_h_14_INCLASS \
	GameCopy_Source_Game_Gun_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_Gun_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_Gun_h_14_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_Gun_h_14_SPARSE_DATA \
	GameCopy_Source_Game_Gun_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_Gun_h_14_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_Gun_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AGun>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_Gun_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

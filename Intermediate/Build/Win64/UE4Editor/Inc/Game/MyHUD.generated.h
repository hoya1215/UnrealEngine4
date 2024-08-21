// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_MyHUD_generated_h
#error "MyHUD.generated.h already included, missing '#pragma once' in MyHUD.h"
#endif
#define GAME_MyHUD_generated_h

#define GameCopy_Source_Game_MyHUD_h_20_SPARSE_DATA
#define GameCopy_Source_Game_MyHUD_h_20_RPC_WRAPPERS
#define GameCopy_Source_Game_MyHUD_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_Source_Game_MyHUD_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyHUD(); \
	friend struct Z_Construct_UClass_UMyHUD_Statics; \
public: \
	DECLARE_CLASS(UMyHUD, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UMyHUD)


#define GameCopy_Source_Game_MyHUD_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUMyHUD(); \
	friend struct Z_Construct_UClass_UMyHUD_Statics; \
public: \
	DECLARE_CLASS(UMyHUD, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UMyHUD)


#define GameCopy_Source_Game_MyHUD_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyHUD(UMyHUD&&); \
	NO_API UMyHUD(const UMyHUD&); \
public:


#define GameCopy_Source_Game_MyHUD_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyHUD(UMyHUD&&); \
	NO_API UMyHUD(const UMyHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyHUD)


#define GameCopy_Source_Game_MyHUD_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MyCharacter() { return STRUCT_OFFSET(UMyHUD, MyCharacter); }


#define GameCopy_Source_Game_MyHUD_h_17_PROLOG
#define GameCopy_Source_Game_MyHUD_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_MyHUD_h_20_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_MyHUD_h_20_SPARSE_DATA \
	GameCopy_Source_Game_MyHUD_h_20_RPC_WRAPPERS \
	GameCopy_Source_Game_MyHUD_h_20_INCLASS \
	GameCopy_Source_Game_MyHUD_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_MyHUD_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_MyHUD_h_20_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_MyHUD_h_20_SPARSE_DATA \
	GameCopy_Source_Game_MyHUD_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_MyHUD_h_20_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_MyHUD_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class UMyHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_MyHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

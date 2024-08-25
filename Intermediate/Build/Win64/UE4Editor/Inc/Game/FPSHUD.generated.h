// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_FPSHUD_generated_h
#error "FPSHUD.generated.h already included, missing '#pragma once' in FPSHUD.h"
#endif
#define GAME_FPSHUD_generated_h

#define GameCopy_4_27_Source_Game_FPSHUD_h_15_SPARSE_DATA
#define GameCopy_4_27_Source_Game_FPSHUD_h_15_RPC_WRAPPERS
#define GameCopy_4_27_Source_Game_FPSHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_4_27_Source_Game_FPSHUD_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSHUD(); \
	friend struct Z_Construct_UClass_AFPSHUD_Statics; \
public: \
	DECLARE_CLASS(AFPSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AFPSHUD)


#define GameCopy_4_27_Source_Game_FPSHUD_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAFPSHUD(); \
	friend struct Z_Construct_UClass_AFPSHUD_Statics; \
public: \
	DECLARE_CLASS(AFPSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AFPSHUD)


#define GameCopy_4_27_Source_Game_FPSHUD_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSHUD(AFPSHUD&&); \
	NO_API AFPSHUD(const AFPSHUD&); \
public:


#define GameCopy_4_27_Source_Game_FPSHUD_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSHUD(AFPSHUD&&); \
	NO_API AFPSHUD(const AFPSHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSHUD)


#define GameCopy_4_27_Source_Game_FPSHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CrosshairTexture() { return STRUCT_OFFSET(AFPSHUD, CrosshairTexture); } \
	FORCEINLINE static uint32 __PPO__Sensitivity() { return STRUCT_OFFSET(AFPSHUD, Sensitivity); }


#define GameCopy_4_27_Source_Game_FPSHUD_h_12_PROLOG
#define GameCopy_4_27_Source_Game_FPSHUD_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_SPARSE_DATA \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_RPC_WRAPPERS \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_INCLASS \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_4_27_Source_Game_FPSHUD_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_SPARSE_DATA \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_INCLASS_NO_PURE_DECLS \
	GameCopy_4_27_Source_Game_FPSHUD_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AFPSHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_4_27_Source_Game_FPSHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

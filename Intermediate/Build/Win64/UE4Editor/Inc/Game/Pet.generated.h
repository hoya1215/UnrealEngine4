// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_Pet_generated_h
#error "Pet.generated.h already included, missing '#pragma once' in Pet.h"
#endif
#define GAME_Pet_generated_h

#define GameCopy_Source_Game_Pet_h_16_SPARSE_DATA
#define GameCopy_Source_Game_Pet_h_16_RPC_WRAPPERS
#define GameCopy_Source_Game_Pet_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_Source_Game_Pet_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPet(); \
	friend struct Z_Construct_UClass_APet_Statics; \
public: \
	DECLARE_CLASS(APet, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(APet)


#define GameCopy_Source_Game_Pet_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAPet(); \
	friend struct Z_Construct_UClass_APet_Statics; \
public: \
	DECLARE_CLASS(APet, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(APet)


#define GameCopy_Source_Game_Pet_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APet(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APet) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APet); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APet(APet&&); \
	NO_API APet(const APet&); \
public:


#define GameCopy_Source_Game_Pet_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APet(APet&&); \
	NO_API APet(const APet&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APet); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APet)


#define GameCopy_Source_Game_Pet_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SkeletalMesh() { return STRUCT_OFFSET(APet, SkeletalMesh); }


#define GameCopy_Source_Game_Pet_h_13_PROLOG
#define GameCopy_Source_Game_Pet_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_Pet_h_16_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_Pet_h_16_SPARSE_DATA \
	GameCopy_Source_Game_Pet_h_16_RPC_WRAPPERS \
	GameCopy_Source_Game_Pet_h_16_INCLASS \
	GameCopy_Source_Game_Pet_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_Pet_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_Pet_h_16_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_Pet_h_16_SPARSE_DATA \
	GameCopy_Source_Game_Pet_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_Pet_h_16_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_Pet_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class APet>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_Pet_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

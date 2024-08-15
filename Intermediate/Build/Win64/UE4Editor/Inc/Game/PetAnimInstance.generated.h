// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_PetAnimInstance_generated_h
#error "PetAnimInstance.generated.h already included, missing '#pragma once' in PetAnimInstance.h"
#endif
#define GAME_PetAnimInstance_generated_h

#define GameCopy_Source_Game_PetAnimInstance_h_16_SPARSE_DATA
#define GameCopy_Source_Game_PetAnimInstance_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAnimNotify_AttackEnd); \
	DECLARE_FUNCTION(execAnimNotify_Attack);


#define GameCopy_Source_Game_PetAnimInstance_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAnimNotify_AttackEnd); \
	DECLARE_FUNCTION(execAnimNotify_Attack);


#define GameCopy_Source_Game_PetAnimInstance_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPetAnimInstance(); \
	friend struct Z_Construct_UClass_UPetAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UPetAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UPetAnimInstance)


#define GameCopy_Source_Game_PetAnimInstance_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUPetAnimInstance(); \
	friend struct Z_Construct_UClass_UPetAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UPetAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(UPetAnimInstance)


#define GameCopy_Source_Game_PetAnimInstance_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPetAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPetAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPetAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPetAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPetAnimInstance(UPetAnimInstance&&); \
	NO_API UPetAnimInstance(const UPetAnimInstance&); \
public:


#define GameCopy_Source_Game_PetAnimInstance_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPetAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPetAnimInstance(UPetAnimInstance&&); \
	NO_API UPetAnimInstance(const UPetAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPetAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPetAnimInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPetAnimInstance)


#define GameCopy_Source_Game_PetAnimInstance_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MyPet() { return STRUCT_OFFSET(UPetAnimInstance, MyPet); }


#define GameCopy_Source_Game_PetAnimInstance_h_13_PROLOG
#define GameCopy_Source_Game_PetAnimInstance_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_PetAnimInstance_h_16_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_PetAnimInstance_h_16_SPARSE_DATA \
	GameCopy_Source_Game_PetAnimInstance_h_16_RPC_WRAPPERS \
	GameCopy_Source_Game_PetAnimInstance_h_16_INCLASS \
	GameCopy_Source_Game_PetAnimInstance_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_PetAnimInstance_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_PetAnimInstance_h_16_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_PetAnimInstance_h_16_SPARSE_DATA \
	GameCopy_Source_Game_PetAnimInstance_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_PetAnimInstance_h_16_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_PetAnimInstance_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class UPetAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_PetAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

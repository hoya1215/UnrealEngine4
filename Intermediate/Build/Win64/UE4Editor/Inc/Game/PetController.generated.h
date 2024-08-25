// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_PetController_generated_h
#error "PetController.generated.h already included, missing '#pragma once' in PetController.h"
#endif
#define GAME_PetController_generated_h

#define GameCopy_4_27_Source_Game_PetController_h_17_SPARSE_DATA
#define GameCopy_4_27_Source_Game_PetController_h_17_RPC_WRAPPERS
#define GameCopy_4_27_Source_Game_PetController_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define GameCopy_4_27_Source_Game_PetController_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPetController(); \
	friend struct Z_Construct_UClass_APetController_Statics; \
public: \
	DECLARE_CLASS(APetController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(APetController)


#define GameCopy_4_27_Source_Game_PetController_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAPetController(); \
	friend struct Z_Construct_UClass_APetController_Statics; \
public: \
	DECLARE_CLASS(APetController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(APetController)


#define GameCopy_4_27_Source_Game_PetController_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APetController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APetController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APetController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APetController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APetController(APetController&&); \
	NO_API APetController(const APetController&); \
public:


#define GameCopy_4_27_Source_Game_PetController_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APetController(APetController&&); \
	NO_API APetController(const APetController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APetController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APetController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APetController)


#define GameCopy_4_27_Source_Game_PetController_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BehaviorTree() { return STRUCT_OFFSET(APetController, BehaviorTree); } \
	FORCEINLINE static uint32 __PPO__BlackboardData() { return STRUCT_OFFSET(APetController, BlackboardData); }


#define GameCopy_4_27_Source_Game_PetController_h_14_PROLOG
#define GameCopy_4_27_Source_Game_PetController_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_4_27_Source_Game_PetController_h_17_PRIVATE_PROPERTY_OFFSET \
	GameCopy_4_27_Source_Game_PetController_h_17_SPARSE_DATA \
	GameCopy_4_27_Source_Game_PetController_h_17_RPC_WRAPPERS \
	GameCopy_4_27_Source_Game_PetController_h_17_INCLASS \
	GameCopy_4_27_Source_Game_PetController_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_4_27_Source_Game_PetController_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_4_27_Source_Game_PetController_h_17_PRIVATE_PROPERTY_OFFSET \
	GameCopy_4_27_Source_Game_PetController_h_17_SPARSE_DATA \
	GameCopy_4_27_Source_Game_PetController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_4_27_Source_Game_PetController_h_17_INCLASS_NO_PURE_DECLS \
	GameCopy_4_27_Source_Game_PetController_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class APetController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_4_27_Source_Game_PetController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

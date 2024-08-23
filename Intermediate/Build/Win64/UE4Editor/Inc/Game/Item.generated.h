// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef GAME_Item_generated_h
#error "Item.generated.h already included, missing '#pragma once' in Item.h"
#endif
#define GAME_Item_generated_h

#define GameCopy_Source_Game_Item_h_41_SPARSE_DATA
#define GameCopy_Source_Game_Item_h_41_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnCharacterOverlap);


#define GameCopy_Source_Game_Item_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnCharacterOverlap);


#define GameCopy_Source_Game_Item_h_41_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAItem(); \
	friend struct Z_Construct_UClass_AItem_Statics; \
public: \
	DECLARE_CLASS(AItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AItem)


#define GameCopy_Source_Game_Item_h_41_INCLASS \
private: \
	static void StaticRegisterNativesAItem(); \
	friend struct Z_Construct_UClass_AItem_Statics; \
public: \
	DECLARE_CLASS(AItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AItem)


#define GameCopy_Source_Game_Item_h_41_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AItem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AItem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItem); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItem(AItem&&); \
	NO_API AItem(const AItem&); \
public:


#define GameCopy_Source_Game_Item_h_41_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItem(AItem&&); \
	NO_API AItem(const AItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItem); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AItem)


#define GameCopy_Source_Game_Item_h_41_PRIVATE_PROPERTY_OFFSET
#define GameCopy_Source_Game_Item_h_38_PROLOG
#define GameCopy_Source_Game_Item_h_41_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_Item_h_41_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_Item_h_41_SPARSE_DATA \
	GameCopy_Source_Game_Item_h_41_RPC_WRAPPERS \
	GameCopy_Source_Game_Item_h_41_INCLASS \
	GameCopy_Source_Game_Item_h_41_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GameCopy_Source_Game_Item_h_41_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GameCopy_Source_Game_Item_h_41_PRIVATE_PROPERTY_OFFSET \
	GameCopy_Source_Game_Item_h_41_SPARSE_DATA \
	GameCopy_Source_Game_Item_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	GameCopy_Source_Game_Item_h_41_INCLASS_NO_PURE_DECLS \
	GameCopy_Source_Game_Item_h_41_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GameCopy_Source_Game_Item_h


#define FOREACH_ENUM_EITEM_TYPE(op) \
	op(EITEM_TYPE::MONEY) 

enum class EITEM_TYPE : uint8;
template<> GAME_API UEnum* StaticEnum<EITEM_TYPE>();

#define FOREACH_ENUM_EEQUIPMENT_TYPE(op) \
	op(EEQUIPMENT_TYPE::MAIN) \
	op(EEQUIPMENT_TYPE::SUB) \
	op(EEQUIPMENT_TYPE::OTHER) \
	op(EEQUIPMENT_TYPE::WING) \
	op(EEQUIPMENT_TYPE::SHOES) \
	op(EEQUIPMENT_TYPE::HEAD) 

enum class EEQUIPMENT_TYPE : uint8;
template<> GAME_API UEnum* StaticEnum<EEQUIPMENT_TYPE>();

#define FOREACH_ENUM_EINVENTORY_TYPE(op) \
	op(EINVENTORY_TYPE::EQUIPMENT) \
	op(EINVENTORY_TYPE::CONSUMPTION) \
	op(EINVENTORY_TYPE::ETC) 

enum class EINVENTORY_TYPE : uint8;
template<> GAME_API UEnum* StaticEnum<EINVENTORY_TYPE>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "Item.h"
#include "MyGameInstance.generated.h"

class USoundManager;
class APoolStorage;
/**
 * 
 */
USTRUCT()
struct FAbility : public FTableRowBase
{
	GENERATED_BODY()

public:
	void SetLevel(int Level)
	{
		this->Power *= Level;
		this->Speed *= Level;
		this->Defense *= Level;
		this->Hp *= Level;
	}


	FAbility& operator+=(const FAbility& Other)
	{
		this->Power += Other.Power;
		this->Speed += Other.Speed;
		this->Defense += Other.Defense;
		this->Hp += Other.Hp;

		return *this;
	}

	FAbility& operator-=(const FAbility& Other)
	{
		this->Power -= Other.Power;
		this->Speed -= Other.Speed;
		this->Defense -= Other.Defense;
		this->Hp -= Other.Hp;

		return *this;
	}


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Defense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Hp;
};


USTRUCT()
struct FCharacterData : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Defense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float NeedExp;
};

USTRUCT()
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName EnhanceStatName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ChangeAmount;

};

USTRUCT()
struct FPetData : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanMagnet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MagnetRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackSpeed;

};

USTRUCT()
struct FClothesData : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Defense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName EnhanceStatName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ChangeAmount;

};

USTRUCT()
struct FEnemyData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float EnemyExp;
};

USTRUCT()
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		EINVENTORY_TYPE InventoryType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		EEQUIPMENT_TYPE EquipmentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	TSubclassOf<AItem> ItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	TSoftObjectPtr<UTexture2D> ItemIcon;
};

class UDataTable;

UCLASS()
class GAME_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance();

	virtual void Init() override;

	FCharacterData* GetStatData(int32 level);
	FAbility* GetItemAbility(FName Name);
	FAbility* GetItemAbilityChange(FName Name);

	FWeaponData* GetWeaponData(FName Name);
	FPetData* GetPetData(FName Name);
	FClothesData* GetClothesData(FName Name);
	FEnemyData* GetEnemyData(FName Name);
	FItemData* GetItemData(FName Name);
	USoundManager* GetSoundManager() { return SoundManager; }

private:
	UPROPERTY()
		class UDataTable* MyStats;

	UPROPERTY()
		UDataTable* ItemAbility;

	UPROPERTY()
		UDataTable* ItemAbilityChange;

	UPROPERTY()
		UDataTable* WeaponData;

	UPROPERTY()
		UDataTable* PetData;

	UPROPERTY()
		UDataTable* ClothesData;

	UPROPERTY()
		UDataTable* EnemyData;

	UPROPERTY()
		UDataTable* ItemData;

	// Sound
	UPROPERTY()
		USoundManager* SoundManager;




public:
	// ItemList
	TMap < FName, TTuple<TSubclassOf<AItem>, int>> ItemList;
	TMap<FName, TSharedPtr<class UTexture2D>> ItemTexture;
	

	UPROPERTY()
		APoolStorage* PoolStorage;
};

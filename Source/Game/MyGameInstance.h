// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "Item.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
USTRUCT()
struct FCharacterData : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHp;
};

USTRUCT()
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Speed;

};

USTRUCT()
struct FEnemyData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHp;
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

	FCharacterData* GetStatData(int32 level);
	FWeaponData* GetWeaponData(FName Name);
	FEnemyData* GetEnemyData(FName Name);
	FItemData* GetItemData(FName Name);

private:
	UPROPERTY()
		class UDataTable* MyStats;

	UPROPERTY()
		UDataTable* WeaponData;

	UPROPERTY()
		UDataTable* EnemyData;

	UPROPERTY()
		UDataTable* ItemData;

public:
	// ItemList
	TMap < FName, TTuple<TSubclassOf<AItem>, int>> ItemList;
	TMap<FName, TSharedPtr<class UTexture2D>> ItemTexture;
	
};

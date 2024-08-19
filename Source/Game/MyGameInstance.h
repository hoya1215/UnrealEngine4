// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
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

private:
	UPROPERTY()
		class UDataTable* MyStats;

	UPROPERTY()
		UDataTable* WeaponData;

	UPROPERTY()
		UDataTable* EnemyData;
	
};

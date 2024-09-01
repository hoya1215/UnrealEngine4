// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectPool.h"
#include "ItemPool.generated.h"

class AItem;
class AMoney;
class APotion;
/**
 * 
 */
UCLASS()
class GAME_API UItemPool : public UObjectPool
{
	GENERATED_BODY()
public:
	UItemPool();

	void BeginPlay(UWorld* World);
	void SpawnItem(FName ItemName, FVector SpawnLocation);
	void ReturnItem(FName ItemName, AItem* ReturnedItem);
	void ReAllocatePool(FName ItemName);


public:
	TMap < FName, TSharedPtr<TQueue<AItem*>>> CanUseItemPool;

private:
	int32 MaxItemCount = 1;
	int32 SurplusItemCount = 5;

	UPROPERTY(VisibleAnywhere)
		TSubclassOf<AMoney> MoneyClass; 
	UPROPERTY(VisibleAnywhere)
		TSubclassOf<APotion> PotionClass;
};

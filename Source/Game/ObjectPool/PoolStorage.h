// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoolStorage.generated.h"

class UStaticMeshComponent;
class UEnemyPool;
class UItemPool;
/**
 * 
 */
UCLASS()
class GAME_API APoolStorage : public AActor
{
	GENERATED_BODY()
	
public:
	APoolStorage();

	virtual void BeginPlay() override;
	

public:


	UPROPERTY()
		UEnemyPool* EnemyPool;

	UPROPERTY()
		UItemPool* ItemPool;
};

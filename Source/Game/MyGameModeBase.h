// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"


UENUM()
enum class EENEMY_TYPE : uint8
{
	ET_DEFAULT UMETA(DisplayName = "Default"),
	ET_SMALL UMETA(DisplayName = "Small"),
	ET_BOSS UMETA(DisplayName = "Boss")
};


class AMyEnemy;
class AFireGun;
class UMyHUD;
class USoundCue;
/**
 * 
 */
UCLASS()
class GAME_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	AMyGameModeBase();

	virtual void BeginPlay() override;

	void SpawnEnemy();

	//void UpdateEnemyCount(AActor* DestroyEnemy);

public:

	UPROPERTY()
		UMyHUD* Widget;

	UPROPERTY()
	TSubclassOf<UMyHUD> HUD_Class;


	// Enemy
	UPROPERTY(VisibleAnywhere)
		TSubclassOf<AMyEnemy> EnemyClass;

	UPROPERTY(VisibleAnywhere)
		TSubclassOf<class AEnemy_Small> EnemySmallClass;

	UPROPERTY(VisibleAnywhere)
		TSubclassOf<class AEnemy_Boss> EnemyBossClass;

	TArray<int32> EnemyTypeCount;
	TArray<int32> MaxEnemyTypeCount;

	FTimerHandle EnemyTimerHandle;

	float SpawnInterval = 3.f;
	float SpawnRadius = 500.f;



	int32 CurrentEnemyCount = 0;
	int32 MaxEnemyCount = 0;

	// Weapon
	UPROPERTY()
		TSubclassOf<AFireGun> FireGunClass;

private:
	UPROPERTY()
		USoundCue* BackGroundMusic;
	
};

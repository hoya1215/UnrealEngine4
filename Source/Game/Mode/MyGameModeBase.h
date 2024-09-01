// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"





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


	//void UpdateEnemyCount(AActor* DestroyEnemy);

public:

	UPROPERTY()
		UMyHUD* Widget;

	UPROPERTY()
	TSubclassOf<UMyHUD> HUD_Class;


	// Weapon
	UPROPERTY()
		TSubclassOf<AFireGun> FireGunClass;

private:
	UPROPERTY()
		USoundCue* BackGroundMusic;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyController.h"
#include "Enemy_BossController.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AEnemy_BossController : public AEnemyController
{
	GENERATED_BODY()

public:
	AEnemy_BossController();

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;
	
};

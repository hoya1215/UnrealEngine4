// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AEnemyController : public AAIController
{
	GENERATED_BODY()
	

public:
	AEnemyController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	void UnSetTarget();
	void SetTarget();

private:
	void RandomMove();

public:
	FTimerHandle TimerHandle;

	UPROPERTY()
		class UBehaviorTree* BehaviorTree;

	UPROPERTY()
		class UBlackboardData* BlackboardData;

	UPROPERTY()
		class AMyCharacter* MyCharacter;

	bool bCharacterDie = false;
};

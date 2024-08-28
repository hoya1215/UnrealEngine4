// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PetController.generated.h"


class UBehaviorTree;
/**
 * 
 */
UCLASS()
class GAME_API APetController : public AAIController
{
	GENERATED_BODY()
	
public:
	APetController();

	virtual void Tick(float DeltaTime) override;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	// Get, Set
	UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }
	
private:
	UPROPERTY()
		UBehaviorTree* BehaviorTree;

	UPROPERTY()
		class UBlackboardData* BlackboardData;
};

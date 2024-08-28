// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_PetAttack.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UBTTask_PetAttack : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_PetAttack();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	bool bIsAttack = false;
	
};

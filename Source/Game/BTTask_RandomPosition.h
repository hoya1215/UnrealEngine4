// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RandomPosition.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UBTTask_RandomPosition : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_RandomPosition();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

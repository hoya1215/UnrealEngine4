// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_SearchAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UBTDecorator_SearchAttackRange : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTDecorator_SearchAttackRange();
	
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};

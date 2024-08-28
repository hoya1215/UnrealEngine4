// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_SearchAttackRange.h"
#include "EnemyController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTDecorator_SearchAttackRange::UBTDecorator_SearchAttackRange()
{
	NodeName = TEXT("SearchAttackRange");
}

bool UBTDecorator_SearchAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn)
	{
		auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));
		if (Target == nullptr)
			return false;

		return bResult && Target->GetDistanceTo(CurrentPawn) <= 200.f;
	}
	return bResult;
}
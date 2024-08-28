// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RandomPosition.h"
#include "EnemyController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_RandomPosition::UBTTask_RandomPosition()
{
	NodeName = TEXT("RandomPosition");
}

EBTNodeResult::Type UBTTask_RandomPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return EBTNodeResult::Failed;

	UNavigationSystemV1* NavySystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavySystem)
	{
		FNavLocation RandomLocation;

		if (NavySystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
		{
			//UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("RandomPosition")), RandomLocation.Location);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CheckPicking.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "MyEnemy.h"

UBTService_CheckPicking::UBTService_CheckPicking()
{
	NodeName = TEXT("CheckPicking");
}

void UBTService_CheckPicking::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (BlackboardComp == nullptr)
    {
        return;
    }

    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController == nullptr)
    {
        return;
    }

    AMyEnemy* CurrentEnemy = Cast<AMyEnemy>(AIController->GetPawn());
    if (CurrentEnemy)
    {
        bool bIsPicking = CurrentEnemy->IsPicking;
        BlackboardComp->SetValueAsBool(TEXT("IsPicking"), bIsPicking);

    }
}


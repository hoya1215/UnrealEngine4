// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CheckAttacking.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "MyEnemy.h" // Adjust this include to your character's header file

UBTService_CheckAttacking::UBTService_CheckAttacking()
{
    NodeName = TEXT("CheckAttacking");

}

void UBTService_CheckAttacking::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
        bool bIsAttacking = CurrentEnemy->IsAttack;
        BlackboardComp->SetValueAsBool(TEXT("IsAttacking"), bIsAttacking);

    }
}

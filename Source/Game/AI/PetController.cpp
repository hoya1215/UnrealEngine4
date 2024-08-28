// Fill out your copyright notice in the Description page of Project Settings.


#include "PetController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Pet.h"

APetController::APetController()
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("BehaviorTree'/Game/Custom/AI/BT_Pet.BT_Pet'"));
	if (BT.Succeeded())
		BehaviorTree = BT.Object;

	static ConstructorHelpers::FObjectFinder<UBlackboardData> BD(TEXT("BlackboardData'/Game/Custom/AI/BB_Pet.BB_Pet'"));
	if (BD.Succeeded())
		BlackboardData = BD.Object;
}

void APetController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//APet* Pet = Cast<APet>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//GetBlackboardComponent()->SetValueAsBool(TEXT("CanAttack"), Pet->bCanAttack);
}

void APetController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemyController::RandomMove, 3.f, true);
	if (UseBlackboard(BlackboardData, Blackboard))
	{
		if (RunBehaviorTree(BehaviorTree))
		{

		}
	}

}

void APetController::OnUnPossess()
{
	Super::OnUnPossess();

}
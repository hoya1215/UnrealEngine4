// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"


AEnemyController::AEnemyController()
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("BehaviorTree'/Game/Custom/AI/BT_Enemy.BT_Enemy'"));
	if (BT.Succeeded())
		BehaviorTree = BT.Object;

	static ConstructorHelpers::FObjectFinder<UBlackboardData> BD(TEXT("BlackboardData'/Game/Custom/AI/BB_Enemy.BB_Enemy'"));
	if (BD.Succeeded())
		BlackboardData = BD.Object;

	MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	MyCharacter->CharacterDie.AddUObject(this, &AEnemyController::UnSetTarget);
	MyCharacter->CharacterRevive.AddUObject(this, &AEnemyController::SetTarget);
}

void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemyController::RandomMove, 3.f, true);
	if (UseBlackboard(BlackboardData, Blackboard))
	{
		if (RunBehaviorTree(BehaviorTree))
		{

		}
	}
	//MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	SetTarget();

}

void AEnemyController::OnUnPossess()
{
	Super::OnUnPossess();

	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void AEnemyController::RandomMove()
{
	auto CurrentPawn = GetPawn();

	UNavigationSystemV1* NavySystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavySystem)
	{
		FNavLocation RandomLocation;

		if (NavySystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
		}
	}
}

void AEnemyController::SetTarget()
{
	bCharacterDie = false;
	GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), MyCharacter);
}

void AEnemyController::UnSetTarget()
{
	bCharacterDie = true;
	GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), nullptr);
}
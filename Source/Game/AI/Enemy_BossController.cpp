// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_BossController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Rock.h"

AEnemy_BossController::AEnemy_BossController()
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("BehaviorTree'/Game/Custom/AI/BT_Enemy_Boss.BT_Enemy_Boss'"));
	if (BT.Succeeded())
		BehaviorTree = BT.Object;

	static ConstructorHelpers::FObjectFinder<UBlackboardData> BD(TEXT("BlackboardData'/Game/Custom/AI/BB_Enemy.BB_Enemy'"));
	if (BD.Succeeded())
		BlackboardData = BD.Object;

	
}

void AEnemy_BossController::BeginPlay()
{
	Super::BeginPlay();

	//
}

void AEnemy_BossController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	GetBlackboardComponent()->SetValueAsBool(TEXT("HaveRock"), false);
}

void AEnemy_BossController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<AActor*> Rocks;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARock::StaticClass(), Rocks);



	if (Rocks.Num() > 0)
	{
		ARock* CurrentRock = Cast<ARock>(Rocks[0]);
		if (CurrentRock)
		{
			GetBlackboardComponent()->SetValueAsObject(TEXT("Rock"), CurrentRock);
		}
	}

	
	//ARock* Rock = Cast<ARock>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	

}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Boss.h"
#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyController.h"
#include "Enemy_BossController.h"

AEnemy_Boss::AEnemy_Boss() : AMyEnemy()
{
	static ConstructorHelpers::FObjectFinder< USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/CityofBrass_Enemies/Meshes/Enemy/Hooker/Hooker_Boss_Mesh.Hooker_Boss_Mesh'"));
	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 288.f), FRotator(0.0f, 0.f, 0.f));

	EnemyType = EENEMY_TYPE::ET_BOSS;

	//AIControllerClass = AEnemy_BossController::StaticClass();
	AIControllerClass = AEnemyController::StaticClass();
}

void AEnemy_Boss::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy_Boss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//void AEnemy_Boss::Die()
//{
//	AMyGameModeBase* GameModeBase = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));
//	if (GameModeBase && GameModeBase->EnemyTypeCount[2] > 0)
//	{
//		GameModeBase->EnemyTypeCount[2]--;
//	}
//
//	AEnemyController* AIController = Cast<AEnemyController>(GetController());
//	if (AIController)
//	{
//		AIController->OnUnPossess();
//		//AIController->Destroy();
//	}
//
//	Destroy();
//}

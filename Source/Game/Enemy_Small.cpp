// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Small.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyController.h"

AEnemy_Small::AEnemy_Small() : AMyEnemy()
{

	// ũ�� , �޽� ����
	static ConstructorHelpers::FObjectFinder< USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/CityofBrass_Enemies/Meshes/Enemy/Archer/Archer.Archer'"));
	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 288.f), FRotator(0.0f, 0.f, 0.f));

	//StartLocation = FVector(0.f, 0.f, 288.f);
	//EndLocation = FVector(0.f, 0.f, -88.f);


	PrimaryActorTick.bCanEverTick = true;

	EnemyType = EENEMY_TYPE::ET_SMALL;
}

void AEnemy_Small::BeginPlay()
{
	Super::BeginPlay();



	//GetCharacterMovement()->GravityScale = 0.0f;
	//GetCharacterMovement()->DisableMovement(); // �̵��� ��Ȱ��ȭ�մϴ�.
	//
	//
	//
	//GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//
	//// ���� ����
	//StartAppear();
}

void AEnemy_Small::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (bIsAppear)
	//{
	//	CurrentAppearTime += DeltaTime;
	//	float Alpha = AppearTime / CurrentAppearTime;
	//
	//	// Lerp�� ����Ͽ� ��ġ�� ����
	//	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Alpha);
	//	SetActorLocation(NewLocation);
	//
	//	// ������ �������� Ȯ��
	//	if (AppearTime >= CurrentAppearTime)
	//	{
	//		EndAppear();
	//	}
	//}

	//FString BoolAsString = FString::Printf(TEXT("The value of bIsTrue is: %s"), IsAttack ? TEXT("true") : TEXT("false"));
	//UE_LOG(LogTemp, Warning, TEXT("IsAttacking : %s"), *BoolAsString);
}

//void AEnemy_Small::Die()
//{
//	AMyGameModeBase* GameModeBase = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));
//	if (GameModeBase && GameModeBase->EnemyTypeCount[1] > 0)
//	{
//		GameModeBase->EnemyTypeCount[1]--;
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

void AEnemy_Small::StartAppear()
{
	bIsAppear = true;
}

void AEnemy_Small::EndAppear()
{
	bIsAppear = false;
	GetCharacterMovement()->GravityScale = 1.0f;
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);

	GetMesh()->SetSimulatePhysics(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

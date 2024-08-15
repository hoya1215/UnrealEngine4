// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Small.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyController.h"

AEnemy_Small::AEnemy_Small() : AMyEnemy()
{

	// 크기 , 메시 조정
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

}

void AEnemy_Small::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}





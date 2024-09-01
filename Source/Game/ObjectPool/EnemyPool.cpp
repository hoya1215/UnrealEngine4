// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPool.h"
#include "Enemy_Small.h"
#include "Enemy_Boss.h"
#include "MyCharacter.h"
#include "Util.h"

UEnemyPool::UEnemyPool()
{
	ConstructorHelpers::FClassFinder<AMyEnemy> ME(TEXT("Blueprint'/Game/Custom/Blueprint/BP_MyEnemy.BP_MyEnemy_C'"));
	if (ME.Succeeded())
		EnemyClass = ME.Class;

	ConstructorHelpers::FClassFinder<AEnemy_Small> ES(TEXT("Blueprint'/Game/Custom/Blueprint/BP_Enemy_Small.BP_Enemy_Small_C'"));
	if (ME.Succeeded())
		EnemySmallClass = ES.Class;


	ConstructorHelpers::FClassFinder<AEnemy_Boss> EB(TEXT("Blueprint'/Game/Custom/Blueprint/BP_Enemy_Boss.BP_Enemy_Boss_C'"));
	if (ME.Succeeded())
		EnemyBossClass = EB.Class;
}

void UEnemyPool::BeginPlay()
{
	MyCharacter = Util::GetMyCharacter(GetOuter()->GetWorld());

	MaxEnemyCount.Add(EENEMY_TYPE::ET_DEFAULT, 3 );
	MaxEnemyCount.Add(EENEMY_TYPE::ET_SMALL, 5);
	MaxEnemyCount.Add(EENEMY_TYPE::ET_BOSS, 1);



	FActorSpawnParameters SpawnParams;


	for (int i = 0; i < MaxEnemyCount[EENEMY_TYPE::ET_DEFAULT]; ++i)
	{
		AMyEnemy* NewEnemy = GetWorld()->SpawnActor<AMyEnemy>(EnemyClass, StoreLocation, FRotator::ZeroRotator, SpawnParams);
		NewEnemy->SetActorEnableCollision(false);
		NewEnemy->SetActorHiddenInGame(true);
		NewEnemy->SetActorTickEnabled(false);

		CanSpawnEnemyPool[EENEMY_TYPE::ET_DEFAULT]->Enqueue(NewEnemy);
	}

	for (int i = 0; i < MaxEnemyCount[EENEMY_TYPE::ET_SMALL]; ++i)
	{
		AEnemy_Small* NewEnemy = GetWorld()->SpawnActor<AEnemy_Small>(EnemySmallClass, StoreLocation, FRotator::ZeroRotator, SpawnParams);
		NewEnemy->SetActorEnableCollision(false);
		NewEnemy->SetActorHiddenInGame(true);
		NewEnemy->SetActorTickEnabled(false);

		CanSpawnEnemyPool[EENEMY_TYPE::ET_SMALL]->Enqueue(NewEnemy);
	}

	for (int i = 0; i < MaxEnemyCount[EENEMY_TYPE::ET_BOSS]; ++i)
	{
		AEnemy_Boss* NewEnemy = GetWorld()->SpawnActor<AEnemy_Boss>(EnemyBossClass, StoreLocation, FRotator::ZeroRotator, SpawnParams);
		NewEnemy->SetActorEnableCollision(false);
		NewEnemy->SetActorHiddenInGame(true);
		NewEnemy->SetActorTickEnabled(false);

		CanSpawnEnemyPool[EENEMY_TYPE::ET_BOSS]->Enqueue(NewEnemy);
	}


}

bool UEnemyPool::SpawnEnemy(EENEMY_TYPE EnemyType)
{
	if (CurrentEnemyCount >= MaxTotalEnemyCount)
		return false;

	if (CanSpawnEnemyPool[EnemyType]->IsEmpty())
		return false;

	FVector SpawnLocation = MyCharacter->GetActorLocation() + FMath::VRand() * SpawnRadius;
	SpawnLocation.Z = MyCharacter->GetActorLocation().Z + 300.f;

	auto SpawnedEnemy = *CanSpawnEnemyPool[EnemyType]->Peek();
	SpawnedEnemy->SetActorEnableCollision(true);
	SpawnedEnemy->SetActorHiddenInGame(false);
	SpawnedEnemy->SetActorTickEnabled(true);
	SpawnedEnemy->SetActorLocation(SpawnLocation);
	SpawnedEnemy->bSpawned = true;

	CanSpawnEnemyPool[EnemyType]->Pop();
	CurrentEnemyCount++;

	return true;
}

void UEnemyPool::ReturnEnemy(EENEMY_TYPE EnemyType, AMyEnemy* ReturnedEnemy)
{
	ReturnedEnemy->SetActorLocation(StoreLocation);
	ReturnedEnemy->SetActorEnableCollision(false);
	ReturnedEnemy->SetActorHiddenInGame(true);
	ReturnedEnemy->SetActorTickEnabled(false);

	CanSpawnEnemyPool[EnemyType]->Enqueue(ReturnedEnemy);

	CurrentEnemyCount--;
}
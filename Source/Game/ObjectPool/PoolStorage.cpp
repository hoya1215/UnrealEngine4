// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPool/PoolStorage.h"
#include "EnemyPool.h"
#include "ItemPool.h"

APoolStorage::APoolStorage()
{
	PrimaryActorTick.bCanEverTick = false;




}

void APoolStorage::BeginPlay()
{
	Super::BeginPlay();
	


	EnemyPool = NewObject<UEnemyPool>(this, UEnemyPool::StaticClass());
	ItemPool = NewObject<UItemPool>(this, UItemPool::StaticClass());

	EnemyPool->StoreLocation = GetActorLocation();
	ItemPool->StoreLocation = GetActorLocation();

	EnemyPool->BeginPlay();
	ItemPool->BeginPlay(GetWorld());
}
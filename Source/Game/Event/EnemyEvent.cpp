// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyEvent.h"
#include "Components/BoxComponent.h"
#include "MyCharacter.h"
#include "Util.h"
#include "MyEnemy.h"
#include "Enemy_Small.h"
#include "Enemy_Boss.h"
#include "MyGameModeBase.h"
#include "EnemyPool.h"
#include "PoolStorage.h"

// Sets default values
AEnemyEvent::AEnemyEvent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetCollisionProfileName(TEXT("Event"));
	Trigger->SetBoxExtent(FVector(30.f, 30.f, 30.f));
	RootComponent = Trigger;
}

// Called when the game starts or when spawned
void AEnemyEvent::BeginPlay()
{
	Super::BeginPlay();

	GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	
	//EnemyPool = NewObject<UEnemyPool>(this, UEnemyPool::StaticClass());

	//EnemyPool->BeginPlay();
}

void AEnemyEvent::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AEnemyEvent::OnCharacterBeginOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AEnemyEvent::OnCharacterEndOverlap);
}

// Called every frame
void AEnemyEvent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyEvent::OnCharacterBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
	if (MyCharacter)
	{
		GetWorldTimerManager().SetTimer(EnemyTimerHandle, this, &AEnemyEvent::SpawnEnemy, SpawnInterval, true);
	}

}

void AEnemyEvent::OnCharacterEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);

	if (MyCharacter)
	{
		GetWorldTimerManager().ClearTimer(EnemyTimerHandle);
	}
}

void AEnemyEvent::SpawnEnemy()
{
	int EnemyIndex = FMath::RandRange(0, GameInstance->PoolStorage->EnemyPool->EnemyTypeCount - 1);
	switch (EnemyIndex)
	{
	case 0:
		GameInstance->PoolStorage->EnemyPool->SpawnEnemy(EENEMY_TYPE::ET_DEFAULT);
		break;
	case 1:
		GameInstance->PoolStorage->EnemyPool->SpawnEnemy(EENEMY_TYPE::ET_SMALL);
		break;
	case 2:
		GameInstance->PoolStorage->EnemyPool->SpawnEnemy(EENEMY_TYPE::ET_BOSS);
		break;
	}

}

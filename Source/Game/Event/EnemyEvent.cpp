// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyEvent.h"
#include "Components/BoxComponent.h"
#include "MyCharacter.h"
#include "Util.h"
#include "MyEnemy.h"
#include "Enemy_Small.h"
#include "Enemy_Boss.h"
#include "MyGameModeBase.h"

// Sets default values
AEnemyEvent::AEnemyEvent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetCollisionProfileName(TEXT("Event"));
	Trigger->SetBoxExtent(FVector(30.f, 30.f, 30.f));
	RootComponent = Trigger;



	ConstructorHelpers::FClassFinder<AMyEnemy> ME(TEXT("Blueprint'/Game/Custom/Blueprint/BP_MyEnemy.BP_MyEnemy_C'"));
	if (ME.Succeeded())
		EnemyClass = ME.Class;

	EnemyTypeCount.Add(0);
	MaxEnemyTypeCount.Add(3);

	ConstructorHelpers::FClassFinder<AEnemy_Small> ES(TEXT("Blueprint'/Game/Custom/Blueprint/BP_Enemy_Small.BP_Enemy_Small_C'"));
	if (ME.Succeeded())
		EnemySmallClass = ES.Class;

	EnemyTypeCount.Add(0);
	MaxEnemyTypeCount.Add(5);

	ConstructorHelpers::FClassFinder<AEnemy_Boss> EB(TEXT("Blueprint'/Game/Custom/Blueprint/BP_Enemy_Boss.BP_Enemy_Boss_C'"));
	if (ME.Succeeded())
		EnemyBossClass = EB.Class;

	EnemyTypeCount.Add(0);
	MaxEnemyTypeCount.Add(1);
}

// Called when the game starts or when spawned
void AEnemyEvent::BeginPlay()
{
	Super::BeginPlay();
	

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



	if (EnemyTypeCount[0] + EnemyTypeCount[1] + EnemyTypeCount[2] >= MaxEnemyCount)
	{
		return;
	}
		ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
		if (!PlayerCharacter || !EnemyClass) return;

		FVector PlayerLocation = PlayerCharacter->GetActorLocation();
		FVector SpawnLocation = PlayerLocation + FMath::VRand() * SpawnRadius;
		SpawnLocation.Z = PlayerCharacter->GetActorLocation().Z + 300.f;
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		int32 EnemyIndex = FMath::RandRange(0, EnemyTypeCount.Num() - 1);

		AMyEnemy* SpawnedEnemy = nullptr;
		switch (EnemyIndex)
		{
		case 0:
			if (MaxEnemyTypeCount[0] > EnemyTypeCount[0])
			{
				SpawnedEnemy = GetWorld()->SpawnActor<AMyEnemy>(EnemyClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);

				if (SpawnedEnemy)
					EnemyTypeCount[0]++;
			}
			break;
		case 1:
			if (MaxEnemyTypeCount[1] > EnemyTypeCount[1])
			{
				SpawnedEnemy = Cast<AMyEnemy>(GetWorld()->SpawnActor<AEnemy_Small>(EnemySmallClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams));
				if (SpawnedEnemy)
					EnemyTypeCount[1]++;
			}
			break;
		case 2:
			if (MaxEnemyTypeCount[2] > EnemyTypeCount[2])
			{
				SpawnedEnemy = Cast<AMyEnemy>(GetWorld()->SpawnActor<AEnemy_Boss>(EnemyBossClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams));
				if (SpawnedEnemy)
					EnemyTypeCount[2]++;
			}
			break;
		}

		//AMyEnemy* SpawnedEnemy = Cast<AMyEnemy>(GetWorld()->SpawnActor<AMyEnemy>(EnemyClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams));

		if (SpawnedEnemy)
		{
			CurrentEnemyCount++;

			//SpawnedEnemy->OnDestroyed.AddDynamic(this, &AMyGameModeBase::UpdateEnemyCount);
		}

		//if (SpawnedEnemy)
		//{
		//	SpawnedEnemy->SetActorHiddenInGame(true); // 지면으로 올라오기 전에는 숨김 처리
		//	// 적의 초기 위치를 지면 아래로 설정
		//	FVector InitialLocation = SpawnLocation;
		//	InitialLocation.Z -= 500.0f;
		//	SpawnedEnemy->SetActorLocation(InitialLocation);

		//	// Behavior Tree를 사용한 행동 로직 시작
		//	// SpawnedEnemy->StartBehaviorTree();
		//}


}

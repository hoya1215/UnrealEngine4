// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"
#include "FPSHUD.h"
#include "MyHUD.h"
#include "MyEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy_Small.h"
#include "Enemy_Boss.h"

AMyGameModeBase::AMyGameModeBase()
{
	ConstructorHelpers::FClassFinder<AMyCharacter> BP_Character(TEXT("Blueprint'/Game/Custom/Blueprint/BP_MyCharacter.BP_MyCharacter_C'"));
	if (BP_Character.Succeeded())
		DefaultPawnClass = BP_Character.Class;

	ConstructorHelpers::FClassFinder<AFPSHUD> HUD(TEXT("Blueprint'/Game/Custom/Blueprint/BP_FPSHUD.BP_FPSHUD_C'"));
	if (HUD.Succeeded())
		HUDClass = HUD.Class;

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

	static ConstructorHelpers::FClassFinder<UMyHUD> UI_HUD(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_HUD.WBP_HUD_C'"));
	if (UI_HUD.Succeeded())
	{
		HUD_Class = UI_HUD.Class;

		Widget = CreateWidget(GetWorld(), HUD_Class);
		if (Widget)
		{
			//Widget->AddToViewport();
			//Widget->RemoveFromViewport(); 제거 
		}
	}


	//EnemyTypeCount = EENEMY_TYPE::ET_ENEMY_TYPE_COUNT;
}

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(EnemyTimerHandle, this, &AMyGameModeBase::SpawnEnemy, SpawnInterval, true);
}

void AMyGameModeBase::SpawnEnemy()
{
	if (EnemyTypeCount[0] + EnemyTypeCount[1] + EnemyTypeCount[2] >= MaxEnemyCount) return;

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (!PlayerCharacter || !EnemyClass) return;

	FVector PlayerLocation = PlayerCharacter->GetActorLocation();
	FVector SpawnLocation = PlayerLocation + FMath::VRand() * SpawnRadius;
	SpawnLocation.Z = 600.f;
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	int32 EnemyIndex = FMath::RandRange(0, EnemyTypeCount.Num()-1);

	AMyEnemy* SpawnedEnemy = nullptr;
	switch (EnemyIndex)
	{
	case 0:
		if (MaxEnemyTypeCount[0] > EnemyTypeCount[0])
		{
			SpawnedEnemy = GetWorld()->SpawnActor<AMyEnemy>(EnemyClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
			
			if(SpawnedEnemy)
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

//void AMyGameModeBase::UpdateEnemyCount(AActor* DestroyEnemy)
//{
//	if (CurrentEnemyCount > 0)
//	{
//		CurrentEnemyCount--;
//	}
//}

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterStatComponent.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "MyGameModeBase.h"
#include "MyHUD.h"
#include "EnhanceWidget.h"
#include "EnhanceSlotWidget.h"

// Sets default values for this component's properties
UMyCharacterStatComponent::UMyCharacterStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	bWantsInitializeComponent = true;

	Level = 1;
}


// Called when the game starts
void UMyCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void UMyCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetLevel(Level);
}

void UMyCharacterStatComponent::SetLevel(int32 CurrentLevel)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(CurrentLevel);
		if (StatData)
		{
			Level = StatData->Level;
			Hp = StatData->MaxHp;
			Power = StatData->Power;
			Defense = StatData->Defense;
		}
	}
}

void UMyCharacterStatComponent::SetHp(float NewHp)
{
	Hp = NewHp;
}

void UMyCharacterStatComponent::SetPower(int32 NewPower)
{
	Power = NewPower;
}

void UMyCharacterStatComponent::SetDefense(int32 NewDefense)
{
	Defense = NewDefense;
}

float UMyCharacterStatComponent::GetMaxHp()
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	
	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(Level);
		if (StatData)
		{
			return StatData->MaxHp;
		}
	}
	// ½ÇÆÐ
	return -1;
}

int32 UMyCharacterStatComponent::GetPowerIncludeLevel(int32 CharacterLevel, int32 EnemyLevel, int32 CurrentPower)
{
	int32 NewPower = CurrentPower + FMath::Min((CharacterLevel - EnemyLevel), MaxLevelDifference);
	if (NewPower < 0)
		NewPower = 0;

	return NewPower;
}

int32 UMyCharacterStatComponent::GetDamageIncludeDefense(int32 EnemyPower, int32 CurrentDefense)
{
	int32 Damage = EnemyPower * ((float)MaxDefense / float(MaxDefense - CurrentDefense));

	return Damage;
}

void UMyCharacterStatComponent::OnAttacked(float DamageAmount)
{
	Hp -= DamageAmount;
	if (Hp < 0)
	{
		Hp = 0;

		MyCharacter->Die();
	}
}

void UMyCharacterStatComponent::UpdateExp(float NewExp)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	auto StatData = MyGameInstance->GetStatData(Level);
	float NeedExp = StatData->NeedExp;


	CurrentExp += NewExp;
	if (CurrentExp >= NeedExp)
	{
		int Value = CurrentExp / NeedExp;
		LevelUp(Value);

		CurrentExp = CurrentExp - (CurrentExp / NeedExp) * NeedExp;

	}

	float ExpRatio = CurrentExp / NeedExp;
	AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (MyGameMode)
	{
		UMyHUD* MyHUD = Cast<UMyHUD>(MyGameMode->Widget);
		MyHUD->UpdateExp(ExpRatio);
	}
}

void UMyCharacterStatComponent::LevelUp(int Value)
{
	if (Level + Value > MaxLevel)
	{
		EnhancePoint += MaxLevel - Level;
		Level = MaxLevel;
		CurrentExp = 100.f;
	}
	else
	{
		EnhancePoint += Value;
		Level += Value;
	}

	MyCharacter->GetEnhanceWidget()->UpdateEnhancePoint();

	AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (MyGameMode)
	{
		UMyHUD* MyHUD = Cast<UMyHUD>(MyGameMode->Widget);
		MyHUD->UpdateLevel(Level);
	}

	SetLevel(Level);
}



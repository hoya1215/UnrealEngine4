// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterStatComponent.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "MyGameModeBase.h"
#include "MyHUD.h"
#include "EnhanceWidget.h"
#include "EnhanceSlotWidget.h"
#include "UIManager.h"

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

	Level = 1;
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(1);
		Ability.Defense = StatData->Defense;
		Ability.Hp = StatData->MaxHp;
		Ability.Power = StatData->Power;
		CurrentHp = StatData->MaxHp;
	}
	

	//SetLevel(1);
}

void UMyCharacterStatComponent::SetLevel(int32 CurrentLevel)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(CurrentLevel);
		if (StatData)
		{
			//Ability.MaxHp = StatData->MaxHp;
			//Ability.Defense = StatData->Defense;
			//Ability.Power = StatData->Power;
			//Ability.Speed = 0;

			Level = StatData->Level;
			CurrentHp = StatData->MaxHp;

		}
	}
}

void UMyCharacterStatComponent::SetHp(float NewHp)
{
	CurrentHp = NewHp;
}

void UMyCharacterStatComponent::SetPower(int32 NewPower)
{
	Ability.Power = NewPower;
}

void UMyCharacterStatComponent::SetDefense(int32 NewDefense)
{
	Ability.Defense = NewDefense;
}

float UMyCharacterStatComponent::GetMaxHp()
{

	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	
	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(Level);
		if (StatData)
		{
			return Ability.Hp;
		}
	}
	// 실패
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
	CurrentHp -= DamageAmount;
	if (CurrentHp < 0)
	{
		CurrentHp = 0;

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
		UUIManager::Get()->GetHUD()->UpdateExp(ExpRatio);
		//UMyHUD* MyHUD = Cast<UMyHUD>(MyGameMode->Widget);
		//MyHUD->UpdateExp(ExpRatio);
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

	UUIManager::Get()->GetEnhanceWidget()->UpdateEnhancePoint();

	AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (MyGameMode)
	{
		UUIManager::Get()->GetHUD()->UpdateLevel(Level);
		//UMyHUD* MyHUD = Cast<UMyHUD>(MyGameMode->Widget);
		//MyHUD->UpdateLevel(Level);
	}

	// 전레벨과의 스탯변동량 더해주기
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	auto PrevStatData = MyGameInstance->GetStatData(Level - Value);
	auto NextStatData = MyGameInstance->GetStatData(Level);

	MyCharacter->Stat->Ability.Hp += NextStatData->MaxHp - PrevStatData->MaxHp;
	MyCharacter->Stat->CurrentHp = MyCharacter->Stat->Ability.Hp;

	MyCharacter->Stat->Ability.Power += NextStatData->Power - PrevStatData->Power;
	MyCharacter->Stat->Ability.Defense += NextStatData->Defense - PrevStatData->Defense;
}



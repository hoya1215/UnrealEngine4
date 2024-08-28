// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterStatComponent.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

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
		}
	}
}

void UMyCharacterStatComponent::SetHp(int32 NewHp)
{
	Hp = NewHp;
}

int32 UMyCharacterStatComponent::GetMaxHp()
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

void UMyCharacterStatComponent::OnAttacked(float DamageAmount)
{
	Hp -= DamageAmount;
	if (Hp < 0)
		Hp = 0;

	UE_LOG(LogTemp, Warning, TEXT("My Hp :  %d"), Hp);
}


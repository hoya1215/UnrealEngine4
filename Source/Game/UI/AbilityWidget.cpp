// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AbilityWidget.h"
#include "MyCharacterStatComponent.h"
#include "MyGameInstance.h"
#include "Components/TextBlock.h"
#include "Util.h"

void UAbilityWidget::NativeConstruct()
{
	Super::NativeConstruct();

	MyCharacter = Util::GetMyCharacter(GetWorld());
	SetAbilityText();
}

void UAbilityWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	SetAbilityText();
}

void UAbilityWidget::SetAbilityText()
{
	FString Power = FString::Printf(TEXT("%d"), MyCharacter->Stat->GetPower());
	FString Hp = FString::Printf(TEXT("%.1f / %.1f"), MyCharacter->Stat->GetHp(), MyCharacter->Stat->GetMaxHp());
	FString Defense = FString::Printf(TEXT("%d"), MyCharacter->Stat->GetDefense());
	FString Speed = FString::Printf(TEXT("%.1f"), MyCharacter->Stat->Ability.Speed);

	PowerText->SetText(FText::FromString(Power));
	HpText->SetText(FText::FromString(Hp));
	DefenseText->SetText(FText::FromString(Defense));
	SpeedText->SetText(FText::FromString(Speed));
}
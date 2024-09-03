// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/EnhanceWidget.h"
#include "EnhanceSlotWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Util.h"
#include "MyCharacterStatComponent.h"

UEnhanceWidget::UEnhanceWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UEnhanceSlotWidget> ES(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_EnhanceSlot.WBP_EnhanceSlot_C'"));
	if (ES.Succeeded())
		EnhanceSlotWidgetClass = ES.Class;
}

void UEnhanceWidget::NativeConstruct()
{
	Super::NativeConstruct();
	MyCharacter = Util::GetMyCharacter(GetWorld());

	ItemSlot->EnhanceWidget = this;

	DefaultText = FString::Printf(TEXT(""));
	CompareText = FString::Printf(TEXT(">"));
	

	CurrentLevel->SetText(FText::FromString(DefaultText));
	NextLevel->SetText(FText::FromString(DefaultText));
	//CurrentStat->SetText(FText::FromString(DefaultText));
	//NextStat->SetText(FText::FromString(DefaultText));
	CompareText1->SetText(FText::FromString(DefaultText));
	//CompareText2->SetText(FText::FromString(DefaultText));

	if (UpgradeButton)
	{
		UpgradeButton->OnClicked.AddDynamic(this, &UEnhanceWidget::ClickUpgradeButton);
	}


	UpdateEnhancePoint();
}

void UEnhanceWidget::ClickUpgradeButton()
{
	if (ItemSlot->CurrentInventorySlot == nullptr)
		return;

	if (MyCharacter->Stat->GetEnhancePoint() > 0 && ItemSlot->CurrentInventorySlot->SlotData.ItemInfo.Level < MaxItemLevel)
	{
		ItemSlot->CurrentInventorySlot->SlotData.ItemInfo.Level++;
		ItemSlot->UpdateText();
		ItemSlot->CurrentInventorySlot->UpdateLevel();

		MyCharacter->Stat->UpdateEnhancePoint(-1);
		UpdateEnhancePoint();
	}

}

void UEnhanceWidget::UpdateEnhancePoint()
{

	FString Point = FString::Printf(TEXT("Point : %d"), MyCharacter->Stat->GetEnhancePoint());
	EnhancePoint->SetText(FText::FromString(Point));

	
}
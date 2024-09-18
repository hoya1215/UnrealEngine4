// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/EnhanceSlotWidget.h"
#include "MyGameInstance.h"
#include "EnhanceWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UEnhanceSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	DefaultData.Count = 0;
	DefaultData.ItemInfo.ItemName = FName(TEXT("NULL"));
	DefaultData.ItemInfo.Level = 0;
	CurrentInventorySlot = nullptr;
}

void UEnhanceSlotWidget::PushItem(UInventorySlotWidget* NewSlot)
{
	CurrentInventorySlot = NewSlot;

	auto ItemData = GameInstance->GetItemData(CurrentInventorySlot->SlotData.ItemInfo.ItemName);
	if (ItemData)
	{
		SlotTexture = ItemData->ItemIcon.LoadSynchronous();
		if (SlotTexture)
		{
			SlotImage->SetBrushFromTexture(SlotTexture);
		}

		UpdateText();
	}
}

void UEnhanceSlotWidget::PullItem()
{
	SlotTexture = DefaultTexture;
	SlotImage->SetBrushFromTexture(SlotTexture);
	CurrentInventorySlot = nullptr;

	EnhanceWidget->CurrentLevel->SetText(FText::FromString(EnhanceWidget->DefaultText));
	EnhanceWidget->NextLevel->SetText(FText::FromString(EnhanceWidget->DefaultText));

	EnhanceWidget->CompareText1->SetText(FText::FromString(EnhanceWidget->DefaultText));

}

void UEnhanceSlotWidget::UpdateText()
{
	if (!CurrentInventorySlot)
	{
		return;
	}

	auto ItemData = GameInstance->GetItemData(CurrentInventorySlot->SlotData.ItemInfo.ItemName);

	FString CurrentLevel = FString::Printf(TEXT("Lv %d"), CurrentInventorySlot->SlotData.ItemInfo.Level);
	EnhanceWidget->CurrentLevel->SetText(FText::FromString(CurrentLevel));


	EnhanceWidget->CompareText1->SetText(FText::FromString(EnhanceWidget->CompareText));


	FName CurrentStatName;
	FString NextLevel;

	if (CurrentInventorySlot->SlotData.ItemInfo.Level >= 5)
	{
		NextLevel = FString::Printf(TEXT("Max"));

	}
	else
	{
		NextLevel = FString::Printf(TEXT("Lv %d"), CurrentInventorySlot->SlotData.ItemInfo.Level + 1);
	}
	EnhanceWidget->NextLevel->SetText(FText::FromString(NextLevel));

	
}

FReply UEnhanceSlotWidget::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    FEventReply Reply;
    Reply.NativeReply = Super::NativeOnMouseButtonDoubleClick(InGeometry, InMouseEvent);

	PullItem();


    return Reply.NativeReply;
}

void UEnhanceSlotWidget::Reset()
{
	PullItem();
}

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
	//float ChangeAmount;
	//float Value;

	//FClothesData* CData;
	//FWeaponData* WData;

	//switch (ItemData->EquipmentType)
	//{
	//case EEQUIPMENT_TYPE::WING:
	//	CData = GameInstance->GetClothesData(CurrentInventorySlot->SlotData.ItemInfo.ItemName);
	//	//CurrentStatName = CData->EnhanceStatName;
	//	//ChangeAmount = CData->ChangeAmount;
	//	//Value = CData->Speed;
	//	break;
	//case EEQUIPMENT_TYPE::SHOES:
	//	CData = GameInstance->GetClothesData(CurrentInventorySlot->SlotData.ItemInfo.ItemName);
	//	//CurrentStatName = CData->EnhanceStatName;
	//	//ChangeAmount = CData->ChangeAmount;
	//	Value = CData->Speed;
	//	break;
	//case EEQUIPMENT_TYPE::HELMET:
	//	CData = GameInstance->GetClothesData(CurrentInventorySlot->SlotData.ItemInfo.ItemName);
	//	CurrentStatName = CData->EnhanceStatName;
	//	ChangeAmount = CData->ChangeAmount;
	//	Value = CData->Defense;
	//	break;
	//default:
	//	WData = GameInstance->GetWeaponData(CurrentInventorySlot->SlotData.ItemInfo.ItemName);
	//	CurrentStatName = WData->EnhanceStatName;
	//	ChangeAmount = WData->ChangeAmount;
	//	Value = WData->Power;
	//	break;
	//}
	FString NextLevel;
	//FString CurrentStat = FString::Printf(TEXT("%s %.1f"), *CurrentStatName.ToString(), Value + (CurrentInventorySlot->SlotData.ItemInfo.Level) * ChangeAmount);
	//FString NextStat = FString::Printf(TEXT("%s %.1f"), *CurrentStatName.ToString(), Value + (CurrentInventorySlot->SlotData.ItemInfo.Level + 1) * ChangeAmount);
	if (CurrentInventorySlot->SlotData.ItemInfo.Level >= 5)
	{
		NextLevel = FString::Printf(TEXT("Max"));
		//NextStat = FString::Printf(TEXT("Max"));
	}
	else
	{
		NextLevel = FString::Printf(TEXT("Lv %d"), CurrentInventorySlot->SlotData.ItemInfo.Level + 1);
	}
	EnhanceWidget->NextLevel->SetText(FText::FromString(NextLevel));
	//EnhanceWidget->CurrentStat->SetText(FText::FromString(CurrentStat));
	//EnhanceWidget->NextStat->SetText(FText::FromString(NextStat));

	
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

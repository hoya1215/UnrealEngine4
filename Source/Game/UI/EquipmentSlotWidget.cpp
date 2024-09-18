// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentSlotWidget.h"
#include "Item.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/TextBlock.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"  
#include "InventoryWidget.h"
#include "InventorySlotWidget.h"
#include "Weapon.h"
#include "Wing.h"
#include "Shoes.h"
#include "Helmet.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyGameInstance.h"
#include "Components/TextBlock.h"
#include "UIManager.h"
#include "ItemStatWidget.h"


void UEquipmentSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	SlotData.ItemInfo.ItemName = FName("NULL");
	SlotData.ItemInfo.Level = 0;

}

void UEquipmentSlotWidget::PushEquipment(FSlotData Data)
{
	auto ItemData = GameInstance->GetItemData(Data.ItemInfo.ItemName);

	SlotTexture = ItemData->ItemIcon.LoadSynchronous();

	SlotImage->SetBrushFromTexture(SlotTexture);
	SlotData = Data;
	FString Level = FString::Printf(TEXT("Lv.%d"), SlotData.ItemInfo.Level);
	LevelText->SetText(FText::FromString(Level));

	ItemStatWidget->FillStatText(Data.ItemInfo);
}

void UEquipmentSlotWidget::PullEquipment()
{
	SlotTexture = DefaultSlotTexture;
	SlotImage->SetBrushFromTexture(DefaultSlotTexture);
	SlotData.ItemInfo.ItemName = FName(TEXT("NULL"));
	SlotData.ItemInfo.Level = 0;
	FString Level = FString::Printf(TEXT(""));
	LevelText->SetText(FText::FromString(Level));

	ItemStatWidget->ResetStatText();
}

FSlotData UEquipmentSlotWidget::SwapEquipment(FSlotData Data)
{
	FSlotData PulledData = SlotData;
	SlotData = Data;
	//AItem* PulledItem = CurrentItem;
	PullEquipment();
	PushEquipment(SlotData);

	return PulledData;
}

FReply UEquipmentSlotWidget::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FEventReply Reply;
	Reply.NativeReply = Super::NativeOnMouseButtonDoubleClick(InGeometry, InMouseEvent);

	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerCharacter && SlotData.ItemInfo.ItemName != FName(TEXT("NULL")))
	{
		// 슬롯에서 해제
		for (int i = 0; i < UUIManager::Get()->GetInventoryWidget()->EquipmentSlotWidgets.Num(); ++i)
		{
			if (UUIManager::Get()->GetInventoryWidget()->EquipmentSlotWidgets[i]->SlotData.ItemInfo.ItemName == FName(TEXT("NULL")))
			{
				UUIManager::Get()->GetInventoryWidget()->EquipmentSlotWidgets[i]->AddItem(SlotData.ItemInfo);
				break;
			}
		}

		// 실제 아이템 장착 해제
		if (SlotData.ItemInfo.ItemName == FName(TEXT("Wing")))
		{
			//PlayerCharacter->UnDressedWing();
			PlayerCharacter->GetMyWing()->UnEquippedItem();
		}
		else if (SlotData.ItemInfo.ItemName == FName(TEXT("Shoes")))
		{
			//PlayerCharacter->UnDressedShoes();
			PlayerCharacter->GetMyShoes()->UnEquippedItem();
		}
		else if (SlotData.ItemInfo.ItemName == FName(TEXT("Helmet")))
		{
			//PlayerCharacter->UnDressedHelmet();
			PlayerCharacter->GetMyHelmet()->UnEquippedItem();
		}
		else
		{
			//PlayerCharacter->UnEquippedWeapon(SlotData.ItemInfo.ItemName);
			if(PlayerCharacter->GetMyWeapon()->ItemInfo.ItemName == SlotData.ItemInfo.ItemName)
				PlayerCharacter->GetMyWeapon()->UnEquippedItem();
		}

		//if (CurrentItem->InventoryType == EINVENTORY_TYPE::EQUIPMENT)
		//{
		//if (ItemName == FName(TEXT("Wing")))
		//{
		//	PlayerCharacter->GetMyWing()->SetActorHiddenInGame(true);
		//	PlayerCharacter->SetMyWing(nullptr);
		//}
		//else
		//{
		//	if (PlayerCharacter->GetMyWeapon() != nullptr &&
		//		PlayerCharacter->GetMyWeapon()->ItemName == ItemName)
		//	{
		//		PlayerCharacter->GetMyWeapon()->Destroy();

		//		PlayerCharacter->SetMyWeapon(nullptr);

		//		// 다음 무기 있으면 장착 

		//	}
		//}

		PullEquipment();

		PlayerCharacter->ChangeSpeed();
		PlayerCharacter->WeaponChange.Broadcast();

	}



	return Reply.NativeReply;
}

void UEquipmentSlotWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

	if (SlotData.ItemInfo.ItemName != FName(TEXT("NULL")))
	{
		ItemStatWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void UEquipmentSlotWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);

	if (SlotData.ItemInfo.ItemName != FName(TEXT("NULL")))
	{
		ItemStatWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

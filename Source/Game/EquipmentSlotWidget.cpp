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


void UEquipmentSlotWidget::PushEquipment(AItem* Item, UTexture2D* Texture)
{
	//UTexture2D* WingTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/Wing.Wing'"));
	//ItemTexture = WingTexture;

	//SlotTexture = WingTexture;
	if (Texture != nullptr)
		SlotTexture = Texture;
	else
		SlotTexture = Item->ItemTexture;
	SlotImage->SetBrushFromTexture(SlotTexture);
	CurrentItem = Item;
}

void UEquipmentSlotWidget::PullEquipment()
{
	SlotTexture = DefaultSlotTexture;
	SlotImage->SetBrushFromTexture(SlotTexture);
	CurrentItem = nullptr;
}

AItem* UEquipmentSlotWidget::SwapEquipment(AItem* NewItem)
{
	AItem* PulledItem = CurrentItem;
	PullEquipment();
	PushEquipment(NewItem);

	return PulledItem;
}

FReply UEquipmentSlotWidget::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FEventReply Reply;
	Reply.NativeReply = Super::NativeOnMouseButtonDoubleClick(InGeometry, InMouseEvent);

	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerCharacter && CurrentItem)
	{
		for (int i = 0; i < PlayerCharacter->GetInventoryWidget()->EquipmentSlotWidgets.Num(); ++i)
		{
			if (PlayerCharacter->GetInventoryWidget()->EquipmentSlotWidgets[i]->SlotItem == nullptr)
			{
				PlayerCharacter->GetInventoryWidget()->EquipmentSlotWidgets[i]->AddItem(CurrentItem);
				break;
			}
		}

		if (CurrentItem->InventoryType == EINVENTORY_TYPE::EQUIPMENT)
		{
			switch (CurrentItem->EquipmentType)
			{
			case EEQUIPMENT_TYPE::MAIN:
				PlayerCharacter->GetMyWeapon()->SetActorHiddenInGame(true);
				PlayerCharacter->SetMyWeapon(nullptr);
				break;
			case EEQUIPMENT_TYPE::WING:
				PlayerCharacter->GetMyWing()->SetActorHiddenInGame(true);
				PlayerCharacter->SetMyWing(nullptr);
			}
		}

		PullEquipment();



	}

	return Reply.NativeReply;
}
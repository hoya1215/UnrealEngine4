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
#include "GameFramework/CharacterMovementComponent.h"


void UEquipmentSlotWidget::PushEquipment(AItem* Item, UTexture2D* Texture)
{
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
			if (PlayerCharacter->GetInventoryWidget()->EquipmentSlotWidgets[i]->CurrentItem == nullptr)
			{
				PlayerCharacter->GetInventoryWidget()->EquipmentSlotWidgets[i]->AddItem(CurrentItem);
				break;
			}
		}

		if (CurrentItem->InventoryType == EINVENTORY_TYPE::EQUIPMENT)
		{
			switch (CurrentItem->EquipmentType)
			{
			case EEQUIPMENT_TYPE::WING:
				PlayerCharacter->GetMyWing()->SetActorHiddenInGame(true);
				PlayerCharacter->SetMyWing(nullptr);
				break;
			default:
				if (PlayerCharacter->GetMyWeapon() != nullptr && 
					PlayerCharacter->GetMyWeapon()->EquipmentType == CurrentItem->EquipmentType)
				{
					
					PlayerCharacter->GetMyWeapon()->SetActorHiddenInGame(true);
					PlayerCharacter->SetMyWeapon(nullptr);
				}
				break;
			}
		}

		PullEquipment();

		PlayerCharacter->ChangeSpeed();

	}



	return Reply.NativeReply;
}
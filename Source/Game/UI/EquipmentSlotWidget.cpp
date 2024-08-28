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
#include "MyGameInstance.h"


void UEquipmentSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

}

void UEquipmentSlotWidget::PushEquipment(FName Name)
{
	auto ItemData = GameInstance->GetItemData(Name);

	SlotTexture = ItemData->ItemIcon.LoadSynchronous();

	SlotImage->SetBrushFromTexture(SlotTexture);
	ItemName = Name;
}

void UEquipmentSlotWidget::PullEquipment()
{
	SlotTexture = DefaultSlotTexture;
	SlotImage->SetBrushFromTexture(DefaultSlotTexture);
	ItemName = FName(TEXT("NULL"));
}

FName UEquipmentSlotWidget::SwapEquipment(FName NewName)
{
	FName PulledName = ItemName;
	ItemName = NewName;
	//AItem* PulledItem = CurrentItem;
	PullEquipment();
	PushEquipment(NewName);

	return PulledName;
}

FReply UEquipmentSlotWidget::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FEventReply Reply;
	Reply.NativeReply = Super::NativeOnMouseButtonDoubleClick(InGeometry, InMouseEvent);

	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerCharacter && ItemName != FName(TEXT("NULL")))
	{
		for (int i = 0; i < PlayerCharacter->GetInventoryWidget()->EquipmentSlotWidgets.Num(); ++i)
		{
			if (PlayerCharacter->GetInventoryWidget()->EquipmentSlotWidgets[i]->ItemName == FName(TEXT("NULL")))
			{
				PlayerCharacter->GetInventoryWidget()->EquipmentSlotWidgets[i]->AddItem(ItemName);
				break;
			}
		}

		//if (CurrentItem->InventoryType == EINVENTORY_TYPE::EQUIPMENT)
		//{
		if (ItemName == FName(TEXT("Wing")))
		{
			PlayerCharacter->GetMyWing()->SetActorHiddenInGame(true);
			PlayerCharacter->SetMyWing(nullptr);
		}
		else
		{
			if (PlayerCharacter->GetMyWeapon() != nullptr &&
				PlayerCharacter->GetMyWeapon()->ItemName == ItemName)
			{
				PlayerCharacter->GetMyWeapon()->Destroy();

				PlayerCharacter->SetMyWeapon(nullptr);

				// 다음 무기 있으면 장착 

			}
		}

			//switch (ItemName)
			//{
			//case EEQUIPMENT_TYPE::WING:
			//	PlayerCharacter->GetMyWing()->SetActorHiddenInGame(true);
			//	PlayerCharacter->SetMyWing(nullptr);
			//	break;
			//default:
			//	if (PlayerCharacter->GetMyWeapon() != nullptr && 
			//		PlayerCharacter->GetMyWeapon()->EquipmentType == CurrentItem->EquipmentType)
			//	{
			//		
			//		PlayerCharacter->GetMyWeapon()->SetActorHiddenInGame(true);
			//		PlayerCharacter->SetMyWeapon(nullptr);
			//	}
			//	break;
			//}
		//}

		PullEquipment();

		PlayerCharacter->ChangeSpeed();
		PlayerCharacter->WeaponChange.Broadcast();

	}



	return Reply.NativeReply;
}
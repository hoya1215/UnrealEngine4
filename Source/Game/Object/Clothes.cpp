// Fill out your copyright notice in the Description page of Project Settings.


#include "Clothes.h"
#include "MyCharacter.h"
#include "InventorySlotWidget.h"
#include "Kismet/GameplayStatics.h"  
#include "InventoryWidget.h"
#include "Pet.h"

AClothes::AClothes()
{
	InventoryType = EINVENTORY_TYPE::EQUIPMENT;

	bCanMagnet = false;
}

void AClothes::UnEquippedItem()
{
	return;
}

void AClothes::OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//FSlotData SlotData;
	//SlotData.ItemName = ItemName;
	//SlotData.Level = Level;

	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	AMyCharacter* Character = Cast<AMyCharacter>(OtherActor);
	APet* MyPet = Cast<APet>(OtherActor);

	if (MyPet || Character)
	{


		if (PlayerCharacter->bCanPickUp)
		{
			PlayerCharacter->GetInventoryWidget()->AddItemToInventory(ItemInfo);
			SetActorEnableCollision(false);
			SetActorHiddenInGame(true);
			SetActorTickEnabled(false);

			Destroy();
		}
		else
		{
			SetActorEnableCollision(false);
			SetActorHiddenInGame(false);
			SetActorTickEnabled(false);
		}

	}
}

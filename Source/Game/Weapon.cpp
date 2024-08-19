// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Kismet/GameplayStatics.h"  
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "MyCharacter.h"
#include "EquipmentWidget.h"
#include "EquipmentSlotWidget.h"

AWeapon::AWeapon()
{
	InventoryType = EINVENTORY_TYPE::EQUIPMENT;


	bCanMagnet = false;
}

AItem* AWeapon::EquippedItem()
{
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerCharacter && PlayerCharacter->GetEquipmentWidget())
	{
		UEquipmentSlotWidget* CurrentSlot = PlayerCharacter->GetEquipmentWidget()->EquipmentSlots[EquipmentType];
		if (CurrentSlot == nullptr)
			return this;

		if (CurrentSlot->CurrentItem)
		{
			// ±³Ã¼
			return CurrentSlot->SwapEquipment(this);
		}
		else
		{
			if (PlayerCharacter->GetMyWeapon() != nullptr)
				CurrentSlot->PushEquipment(this);
			else
			{
				// ÀåÂø
				CurrentSlot->PushEquipment(this);

				// ÀåÂø
				FName GunSocket(TEXT("middle_r_socket"));

				AttachToComponent(PlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
					GunSocket);
				SetActorRotation(FRotator(0.f, 0.f, 0.f));
				PlayerCharacter->SetMyWeapon(this);
				SetActorHiddenInGame(false);
				PlayerCharacter->CurrentWeaponState = WeaponState;
			}


			return nullptr;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Equipped Failed !"));
	return this;

}

void AWeapon::SetWeaponInfo(FName Name)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	auto WeaponData = MyGameInstance->GetWeaponData(Name);

	WeaponInfo.Power = WeaponData->Power;
	WeaponInfo.Speed = WeaponData->Speed;
}
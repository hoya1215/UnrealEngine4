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

FName AWeapon::EquippedItem()
{
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerCharacter && PlayerCharacter->GetEquipmentWidget())
	{
		UEquipmentSlotWidget* CurrentSlot = PlayerCharacter->GetEquipmentWidget()->EquipmentSlots[EquipmentType];

		// ���� ���Կ� �������� �������
		if (CurrentSlot->ItemName != FName(TEXT("NULL")))
		{
			// ��ü
			// ������ �ִ� �� destroy
			return CurrentSlot->SwapEquipment(ItemName);
		}
		else // �ٸ� ����
		{
			// ���� ���� �ִ� ���
			if (PlayerCharacter->GetMyWeapon() != nullptr)
			{
				CurrentSlot->PushEquipment(ItemName);
				return FName(TEXT("Destroy"));
				//Destroy();
			}
			else
			{
				// ����
				CurrentSlot->PushEquipment(ItemName);

				AttachToCharacter();
				//// ����
				//FName GunSocket(TEXT("middle_r_socket"));
				//
				//AttachToComponent(PlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
				//	GunSocket);
				//SetActorRotation(FRotator(0.f, 0.f, 0.f));
				//PlayerCharacter->SetMyWeapon(this);
				//SetActorHiddenInGame(false);
				//PlayerCharacter->CurrentWeaponState = WeaponState;
			}


			return FName(TEXT("NULL"));
		}
	}

	return FName(TEXT("NULL"));

}

void AWeapon::AttachToCharacter()
{
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	// ����
	FName GunSocket(TEXT("middle_r_socket"));
	FName GunSocket_r(TEXT("middle_r_03"));

	if (WeaponState == 1)
	{
		AttachToComponent(PlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			GunSocket_r);
	}
	else
	{
		AttachToComponent(PlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			GunSocket);
	}
	SetActorRelativeRotation(RelativeRotation);
	//SetActorRelativeRotation(FRotator(0.f, 0.f, 0.f));
	PlayerCharacter->SetMyWeapon(this);
	SetActorHiddenInGame(false);
	PlayerCharacter->CurrentWeaponState = WeaponState;
	PlayerCharacter->SetWeaponStat(ItemName, true);
}

void AWeapon::SetWeaponInfo(FName Name)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	auto WeaponData = MyGameInstance->GetWeaponData(Name);

	WeaponInfo.Power = WeaponData->Power;
	WeaponInfo.Speed = WeaponData->Speed;
}
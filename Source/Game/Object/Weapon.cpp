// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Kismet/GameplayStatics.h"  
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "MyCharacter.h"
#include "EquipmentWidget.h"
#include "EquipmentSlotWidget.h"
#include "InventoryWidget.h"
#include "Pet.h"
#include "Util.h"

AWeapon::AWeapon()
{
	InventoryType = EINVENTORY_TYPE::EQUIPMENT;


	bCanMagnet = false;
}

void AWeapon::UnEquippedItem()
{
	AMyCharacter* MyCharacter = Util::GetMyCharacter(GetWorld());

	if (MyCharacter->GetMyWeapon() != nullptr && MyCharacter->GetMyWeapon()->ItemName == ItemInfo.ItemName)
	{
		MyCharacter->SetWeaponStat(ItemInfo.ItemName, false);

		MyCharacter->SetMyWeapon(nullptr);

		// ���� ���� ������ ���� 

	}

	Destroy();
}

void AWeapon::OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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

	//Destroy();
}

void AWeapon::EquippedItem(FItemInfo Info)
{
	FSlotData SlotData;

	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	//if (PlayerCharacter && PlayerCharacter->GetEquipmentWidget())
	//{
	//	UEquipmentSlotWidget* CurrentSlot = PlayerCharacter->GetEquipmentWidget()->EquipmentSlots[EquipmentType];

	//	SlotData.ItemName = ItemName;
	//	SlotData.Level = Level;
	//	// ���� ���Կ� �������� �������
	//	if (CurrentSlot->SlotData.ItemName != FName(TEXT("NULL")))
	//	{
	//		// ��ü
	//		// ������ �ִ� �� destroy

	//		return CurrentSlot->SwapEquipment(SlotData);
	//	}
	//	else // �ٸ� ����
	//	{
	//		// ���� ���� �ִ� ���
	//		if (PlayerCharacter->GetMyWeapon() != nullptr)
	//		{

	//			CurrentSlot->PushEquipment(SlotData);
	//			SlotData.ItemName = FName(TEXT("Destroy"));
	//			return SlotData;
	//			//Destroy();
	//		}
	//		else
	//		{
	//			// ����
	//			CurrentSlot->PushEquipment(SlotData);

	//			AttachToCharacter();
	//			//// ����
	//			//FName GunSocket(TEXT("middle_r_socket"));
	//			//
	//			//AttachToComponent(PlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
	//			//	GunSocket);
	//			//SetActorRotation(FRotator(0.f, 0.f, 0.f));
	//			//PlayerCharacter->SetMyWeapon(this);
	//			//SetActorHiddenInGame(false);
	//			//PlayerCharacter->CurrentWeaponState = WeaponState;
	//		}


	//		SlotData.ItemName = FName(TEXT("NULL"));
	//		return SlotData;
	//	}
	//}

	//SlotData.ItemName = FName(TEXT("NULL"));
	//return SlotData;

	AttachToCharacter();

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
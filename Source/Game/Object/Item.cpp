// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/BoxComponent.h"
#include "InventoryComponent.h"
#include "MyCharacter.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.h"
#include "Pet.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"
#include "ItemPool.h"
#include "PoolStorage.h"
#include "Util.h"
#include "MyCharacterStatComponent.h"

AItem::AItem()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetCollisionProfileName(TEXT("Item"));
	Trigger->SetBoxExtent(FVector(30.f, 30.f, 30.f));


	ItemInfo.Level = 0;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnCharacterOverlap);
}

void AItem::OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	AMyCharacter* Character = Cast<AMyCharacter>(OtherActor);
	APet* MyPet = Cast<APet>(OtherActor);

	//FSlotData SlotData;
	//SlotData.ItemName = ItemName;
	//SlotData.Level = Level;

	if (MyPet || Character)
	{
		PlayerCharacter->GetInventoryWidget()->AddItemToInventory(ItemInfo);
		GameInstance->PoolStorage->ItemPool->ReturnItem(ItemInfo.ItemName, this);

		//if (PlayerCharacter->bCanPickUp)
		//{
		//	PlayerCharacter->GetInventoryWidget()->AddItemToInventory(ItemName);
		//	SetActorEnableCollision(false);
		//	SetActorHiddenInGame(true);
		//	SetActorTickEnabled(false);

		//	Destroy();
		//}
		//else
		//{
		//	SetActorEnableCollision(false);
		//	SetActorHiddenInGame(false);
		//	SetActorTickEnabled(false);
		//}

	}

	//Destroy();
}


void AItem::EquippedItem(FItemInfo Item)
{
	return;
}

void AItem::UnEquippedItem()
{
	return;
}

void AItem::AttachToCharacter()
{

}

void AItem::SetItemInfo(FItemInfo NewInfo)
{
	ItemInfo = NewInfo;
}

void AItem::UseItem()
{

}

void AItem::SetCharacterStat(bool Plus)
{
	// 기본 스탯 가져오고 레벨에 따라 변동량 가져와서 더해주고 캐릭터와 더해주기
	UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	auto BasicAbility = GameInstance->GetItemAbility(ItemInfo.ItemName);
	auto AbilityChange = GameInstance->GetItemAbilityChange(ItemInfo.ItemName);

	//AbilityChange->SetLevel(ItemInfo.Level);



	AMyCharacter* MyCharacter = Util::GetMyCharacter(GetWorld());
	if (Plus)
	{
		MyCharacter->Stat->Ability += *BasicAbility;
		for (int i = 0; i < ItemInfo.Level; ++i)
		{
			MyCharacter->Stat->Ability += *AbilityChange;
		}
	}
	else
	{
		MyCharacter->Stat->Ability -= *BasicAbility;
		for (int i = 0; i < ItemInfo.Level; ++i)
		{
			MyCharacter->Stat->Ability -= *AbilityChange;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Level %d"), ItemInfo.Level);
	UE_LOG(LogTemp, Warning, TEXT("Power %d"), BasicAbility->Power);
}


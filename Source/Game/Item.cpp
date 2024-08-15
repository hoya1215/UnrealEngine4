// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/BoxComponent.h"
#include "InventoryComponent.h"
#include "MyCharacter.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.h"
#include "Pet.h"
#include "Kismet/GameplayStatics.h"


AItem::AItem()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetCollisionProfileName(TEXT("Item"));
	Trigger->SetBoxExtent(FVector(30.f, 30.f, 30.f));
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


	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	AMyCharacter* Character = Cast<AMyCharacter>(OtherActor);
	APet* MyPet = Cast<APet>(OtherActor);

	if (MyPet || Character)
	{
		PlayerCharacter->GetInventory()->AddToInventory(ItemType);
		//UTexture2D* CurrentItemTexture = PlayerCharacter->GetInventory()->GetTexture(ItemType);
		PlayerCharacter->GetInventoryWidget()->AddItemToInventory(this);
		SetActorEnableCollision(false);
		SetActorHiddenInGame(true);
		SetActorTickEnabled(false);
	}
}


AItem* AItem::EquippedItem()
{
	return this;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Potion.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "MyGameInstance.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h" 
#include "InventoryWidget.h"
#include "Components/TextBlock.h"

APotion::APotion()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Potion"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Fantastic_Village_Pack/meshes/props/food/SM_PROP_bottle_06.SM_PROP_bottle_06'"));
	if (SM.Succeeded())
		StaticMesh->SetStaticMesh(SM.Object);

	RootComponent = StaticMesh;

	Trigger->SetupAttachment(StaticMesh);
	StaticMesh->SetCollisionProfileName(TEXT("Item"));
	StaticMesh->SetSimulatePhysics(false);
	StaticMesh->SetEnableGravity(false);

	Value = FMath::RandRange(500, 1000);

	ItemInfo.ItemName = FName(TEXT("Potion"));
	ItemType = EITEM_TYPE::POTION;
	InventoryType = EINVENTORY_TYPE::CONSUMPTION;


	ItemClass = APotion::StaticClass();
	Value = 50.f;
}

void APotion::UseItem()
{
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	PotionFunction::RecoverHp(MyCharacter, Value);

	Destroy();
}

void APotion::BeginPlay()
{
	Super::BeginPlay();
}
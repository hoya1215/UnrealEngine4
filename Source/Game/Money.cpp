// Fill out your copyright notice in the Description page of Project Settings.


#include "Money.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

AMoney::AMoney()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Money"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Fantastic_Village_Pack/meshes/props/food/SM_PROP_sack_07.SM_PROP_sack_07'"));
	if (SM.Succeeded())
		Mesh->SetStaticMesh(SM.Object);

	RootComponent = Mesh;

	Trigger->SetupAttachment(Mesh);
	Mesh->SetCollisionProfileName(TEXT("Item"));
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(true);

	Value = FMath::RandRange(500, 1000);

	ItemName = FName(TEXT("Money"));
	ItemType = EITEM_TYPE::MONEY;
	InventoryType = EINVENTORY_TYPE::CONSUMPTION;

	UTexture2D* MoneyTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Fantastic_Village_Pack/textures/T_gold_BC.T_gold_BC'"));
	ItemTexture = MoneyTexture;
}
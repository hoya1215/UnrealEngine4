// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Helmet.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"  
#include "MyCharacter.h"
#include "EquipmentWidget.h"
#include "EquipmentSlotWidget.h"
#include "MyGameInstance.h"


AHelmet::AHelmet()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/CityofBrass_Enemies/Meshes/Enemy/Corpse_Spear/CorpseSpear_Helmet.CorpseSpear_Helmet'"));
	if (SM.Succeeded())
		StaticMesh->SetStaticMesh(SM.Object);

	RootComponent = StaticMesh;
	Trigger->SetupAttachment(StaticMesh);
	EquipmentType = EEQUIPMENT_TYPE::HELMET;



	ItemName = FName(TEXT("Helmet"));
	ItemClass = AHelmet::StaticClass();

	HelmetStaticMesh = SM.Object;
}

void AHelmet::BeginPlay()
{
	Super::BeginPlay();
}

FName AHelmet::EquippedItem()
{
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerCharacter && PlayerCharacter->GetEquipmentWidget())
	{
		UEquipmentSlotWidget* CurrentSlot = PlayerCharacter->GetEquipmentWidget()->EquipmentSlots[EquipmentType];


		if (CurrentSlot->ItemName != FName(TEXT("NULL")))
		{
			// ±³Ã¼
			return CurrentSlot->SwapEquipment(ItemName);
		}
		else
		{

			// ÀåÂø
			CurrentSlot->PushEquipment(ItemName);

			// ÀåÂø
			TArray<UStaticMeshComponent*> StaticMeshComponents;
			PlayerCharacter->GetComponents<UStaticMeshComponent>(StaticMeshComponents);

			for (UStaticMeshComponent* Comp : StaticMeshComponents)
			{
				if (Comp->GetFName() == FName(TEXT("Helmet")))
				{
					Comp->SetStaticMesh(HelmetStaticMesh);
				}
			}

			PlayerCharacter->SetMyHelmet(this);
			SetActorHiddenInGame(true);

			return FName(TEXT("NULL"));
		}
	}

	return FName(TEXT("NULL"));
}

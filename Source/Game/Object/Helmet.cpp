// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Helmet.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"  
#include "MyCharacter.h"
#include "EquipmentWidget.h"
#include "EquipmentSlotWidget.h"
#include "MyGameInstance.h"
#include "Util.h"


AHelmet::AHelmet()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/CityofBrass_Enemies/Meshes/Enemy/Corpse_Spear/CorpseSpear_Helmet.CorpseSpear_Helmet'"));
	if (SM.Succeeded())
		StaticMesh->SetStaticMesh(SM.Object);

	RootComponent = StaticMesh;
	Trigger->SetupAttachment(StaticMesh);
	EquipmentType = EEQUIPMENT_TYPE::HELMET;



	ItemInfo.ItemName = FName(TEXT("Helmet"));
	ItemClass = AHelmet::StaticClass();

	HelmetStaticMesh = SM.Object;
}

void AHelmet::BeginPlay()
{
	Super::BeginPlay();
}

void AHelmet::EquippedItem(FItemInfo Info)
{
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	//FSlotData SlotData;

	//if (PlayerCharacter && PlayerCharacter->GetEquipmentWidget())
	//{
	//	UEquipmentSlotWidget* CurrentSlot = PlayerCharacter->GetEquipmentWidget()->EquipmentSlots[EquipmentType];

	//	SlotData.ItemName = ItemName;
	//	SlotData.Level = Level;

	//	if (CurrentSlot->SlotData.ItemName != FName(TEXT("NULL")))
	//	{
	//		// ±³Ã¼
	//		return CurrentSlot->SwapEquipment(SlotData);
	//	}
	//	else
	//	{

	//		// ÀåÂø
	//		CurrentSlot->PushEquipment(SlotData);

	//		// ÀåÂø
	//		TArray<UStaticMeshComponent*> StaticMeshComponents;
	//		PlayerCharacter->GetComponents<UStaticMeshComponent>(StaticMeshComponents);

	//		for (UStaticMeshComponent* Comp : StaticMeshComponents)
	//		{
	//			if (Comp->GetFName() == FName(TEXT("Helmet")))
	//			{
	//				Comp->SetStaticMesh(HelmetStaticMesh);
	//			}
	//		}

	//		PlayerCharacter->SetMyHelmet(this);
	//		PlayerCharacter->SetClothesStat(ItemName, true);
	//		SetActorHiddenInGame(true);

	//		SlotData.ItemName = FName(TEXT("NULL"));
	//		return SlotData;
	//	}
	//}

	//SlotData.ItemName = FName(TEXT("NULL"));
	//return SlotData;

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
	SetCharacterStat(true);
	//PlayerCharacter->SetClothesStat(ItemName, true);
	SetActorHiddenInGame(true);
}

void AHelmet::UnEquippedItem()
{
	AMyCharacter* MyCharacter = Util::GetMyCharacter(GetWorld());
	TArray<UStaticMeshComponent*> StaticMeshComponents;
	MyCharacter->GetComponents<UStaticMeshComponent>(StaticMeshComponents);

	for (UStaticMeshComponent* Comp : StaticMeshComponents)
	{
		if (Comp->GetFName() == FName(TEXT("Helmet")))
		{
			Comp->SetStaticMesh(nullptr);
		}
	}

	if (MyCharacter->GetMyHelmet())
	{
		//MyCharacter->SetClothesStat(MyCharacter->GetMyHelmet()->ItemName, false);
		SetCharacterStat(false);
		
		MyCharacter->SetMyHelmet(nullptr);
	}

	Destroy();
}

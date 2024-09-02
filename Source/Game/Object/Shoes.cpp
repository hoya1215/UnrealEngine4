// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Shoes.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"  
#include "MyCharacter.h"
#include "EquipmentWidget.h"
#include "EquipmentSlotWidget.h"
#include "MyGameInstance.h"
#include "Util.h"

AShoes::AShoes()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/base-boots-mesh-free/source/Boots/Boots.Boots'"));
	if (SM.Succeeded())
		StaticMesh->SetStaticMesh(SM.Object);

	RootComponent = StaticMesh;
	Trigger->SetupAttachment(StaticMesh);
	EquipmentType = EEQUIPMENT_TYPE::SHOES;

	SetActorScale3D(FVector(0.1f, 0.1f, 0.1f));


	ItemInfo.ItemName = FName(TEXT("Shoes"));
	ItemClass = AShoes::StaticClass();

	ShoesStaticMesh = SM.Object;
}

void AShoes::BeginPlay()
{
	Super::BeginPlay();
}

void AShoes::EquippedItem(FItemInfo Info)
{
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	//FSlotData SlotData;

	//if (PlayerCharacter && PlayerCharacter->GetEquipmentWidget())
	//{
	//	UEquipmentSlotWidget* CurrentSlot = PlayerCharacter->GetEquipmentWidget()->EquipmentSlots[EquipmentType];

	//	
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
	//			if (Comp->GetFName() == FName(TEXT("Shoes_l")) || Comp->GetFName() == FName(TEXT("Shoes_r")) )
	//			{
	//				Comp->SetStaticMesh(ShoesStaticMesh);
	//			}
	//		}

	//		PlayerCharacter->SetMyShoes(this);
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
		if (Comp->GetFName() == FName(TEXT("Shoes_l")) || Comp->GetFName() == FName(TEXT("Shoes_r")))
		{
			Comp->SetStaticMesh(ShoesStaticMesh);
		}
	}

	PlayerCharacter->SetMyShoes(this);
	SetCharacterStat(true);
	//PlayerCharacter->SetClothesStat(ItemName, true);
	SetActorHiddenInGame(true);
}

void AShoes::UnEquippedItem()
{
	AMyCharacter* MyCharacter = Util::GetMyCharacter(GetWorld());

	TArray<UStaticMeshComponent*> StaticMeshComponents;
	MyCharacter->GetComponents<UStaticMeshComponent>(StaticMeshComponents);

	for (UStaticMeshComponent* Comp : StaticMeshComponents)
	{
		if (Comp->GetFName() == FName(TEXT("Shoes_l")) || Comp->GetFName() == FName(TEXT("Shoes_r")))
		{
			Comp->SetStaticMesh(nullptr);
		}
	}

	if (MyCharacter->GetMyShoes())
	{
		//MyCharacter->SetClothesStat(MyCharacter->GetMyShoes()->ItemName, false);
		SetCharacterStat(false);
		
		MyCharacter->SetMyShoes(nullptr);
	}

	Destroy();
}

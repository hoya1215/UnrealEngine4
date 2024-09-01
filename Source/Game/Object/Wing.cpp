// Fill out your copyright notice in the Description page of Project Settings.


#include "Wing.h"
#include "Kismet/GameplayStatics.h"  
#include "MyCharacter.h"
#include "EquipmentWidget.h"
#include "EquipmentSlotWidget.h"
#include "MyGameInstance.h"
#include "Util.h"

AWing::AWing()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/GoodWing/FX_Source/Mesh/SM_GW_Shape_06.SM_GW_Shape_06'"));
	if (SM.Succeeded())
		StaticMesh->SetStaticMesh(SM.Object);

	RootComponent = StaticMesh;
	EquipmentType = EEQUIPMENT_TYPE::WING;

	//UTexture2D* WingTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/Wing.Wing'"));
	//ItemTexture = MakeShareable(WingTexture);


	ItemInfo.ItemName = FName(TEXT("Wing"));
	ItemClass = AWing::StaticClass();
	//SetActorRotation(FRotator(-85.f, 85.f, 81.f));
}

void AWing::BeginPlay()
{
	Super::BeginPlay();

	//UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	//auto List = GameInstance->ItemList.Find(ItemName);
	//if (List == nullptr)
	//{
	//	GameInstance->ItemList.Add(ItemName, MakeTuple(ItemClass, 0));
	//	GameInstance->ItemTexture.Add(ItemName, ItemTexture);
	//}
}

void AWing::EquippedItem(FItemInfo Info)
{
	FSlotData SlotData;

	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

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
	//		FName WingSocket(TEXT("Wing_Socket"));

	//		
	//		AttachToComponent(PlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
	//			WingSocket);
	//		SetActorRelativeRotation(FRotator(270.f, 0.f, 0.f));
	//		PlayerCharacter->SetMyWing(this);
	//		SetActorHiddenInGame(false);

	//		SlotData.ItemName = FName(TEXT("NULL"));
	//		return SlotData;
	//	}
	//}

	//SlotData.ItemName = FName(TEXT("NULL"));
	//return SlotData;

	// ÀåÂø
	FName WingSocket(TEXT("Wing_Socket"));


	AttachToComponent(PlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		WingSocket);
	SetActorRelativeRotation(FRotator(270.f, 0.f, 0.f));
	PlayerCharacter->SetMyWing(this);
	SetActorHiddenInGame(false);
}

void AWing::UnEquippedItem()
{
	AMyCharacter* MyCharacter = Util::GetMyCharacter(GetWorld());

	if (MyCharacter->GetMyWing() != nullptr)
	{
		MyCharacter->GetMyWing()->SetActorHiddenInGame(true);
		MyCharacter->SetMyWing(nullptr);
	}
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Wing.h"
#include "Kismet/GameplayStatics.h"  
#include "MyCharacter.h"
#include "EquipmentWidget.h"
#include "EquipmentSlotWidget.h"
#include "MyGameInstance.h"


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


	ItemName = FName(TEXT("Wing"));
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

FName AWing::EquippedItem()
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
			FName WingSocket(TEXT("Wing_Socket"));

			
			AttachToComponent(PlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
				WingSocket);
			SetActorRelativeRotation(FRotator(270.f, 0.f, 0.f));
			PlayerCharacter->SetMyWing(this);
			SetActorHiddenInGame(false);

			return FName(TEXT("NULL"));
		}
	}

	return FName(TEXT("NULL"));
}
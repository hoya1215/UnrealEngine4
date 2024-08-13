// Fill out your copyright notice in the Description page of Project Settings.


#include "Wing.h"
#include "Kismet/GameplayStatics.h"  
#include "MyCharacter.h"
#include "EquipmentWidget.h"
#include "EquipmentSlotWidget.h"

AWing::AWing()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/GoodWing/FX_Source/Mesh/SM_GW_Shape_06.SM_GW_Shape_06'"));
	if (SM.Succeeded())
		StaticMesh->SetStaticMesh(SM.Object);

	RootComponent = StaticMesh;
	EquipmentType = EEQUIPMENT_TYPE::WING;



	//SetActorRotation(FRotator(-85.f, 85.f, 81.f));
}

AItem* AWing::EquippedItem()
{
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerCharacter && PlayerCharacter->GetEquipmentWidget())
	{
		UEquipmentSlotWidget* CurrentSlot = PlayerCharacter->GetEquipmentWidget()->EquipmentSlots[EquipmentType];
		if (CurrentSlot == nullptr)
			return this;

		if (CurrentSlot->CurrentItem)
		{
			// ±³Ã¼
			return CurrentSlot->SwapEquipment(this);
		}
		else
		{
			UTexture2D* WingTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/Wing.Wing'"));
			ItemTexture = WingTexture;


			// ÀåÂø
			CurrentSlot->PushEquipment(this);

			// ÀåÂø
			FName WingSocket(TEXT("Wing_Socket"));

			
			AttachToComponent(PlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
				WingSocket);
			SetActorRelativeRotation(FRotator(270.f, 0.f, 0.f));
			PlayerCharacter->SetMyWing(this);
			SetActorHiddenInGame(false);

			return nullptr;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Equipped Failed !"));
	return this;
}
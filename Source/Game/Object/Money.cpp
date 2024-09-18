// Fill out your copyright notice in the Description page of Project Settings.


#include "Money.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "MyGameInstance.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h" 
#include "InventoryWidget.h"
#include "Components/TextBlock.h"
#include "UIManager.h"

AMoney::AMoney()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Money"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Fantastic_Village_Pack/meshes/props/food/SM_PROP_sack_07.SM_PROP_sack_07'"));
	if (SM.Succeeded())
		Mesh->SetStaticMesh(SM.Object);

	RootComponent = Mesh;

	Trigger->SetupAttachment(Mesh);
	Mesh->SetCollisionProfileName(TEXT("Item"));
	Mesh->SetSimulatePhysics(false);
	Mesh->SetEnableGravity(false);

	Value = FMath::RandRange(500, 1000);

	ItemInfo.ItemName = FName(TEXT("Money"));
	ItemType = EITEM_TYPE::MONEY;
	InventoryType = EINVENTORY_TYPE::CONSUMPTION;

	//UTexture2D* MoneyTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Fantastic_Village_Pack/textures/T_gold_BC.T_gold_BC'"));
	//ItemTexture = MakeShareable(MoneyTexture);

	ItemClass = AMoney::StaticClass();
}

void AMoney::UseItem()
{
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	int32 MoneyAmount = FMath::RandRange(100, 300);
	UUIManager::Get()->GetInventoryWidget()->CurrentMoney += MoneyAmount;

	const FString MoneyText = FString::Printf(TEXT("%d"), MoneyAmount);
	UUIManager::Get()->GetInventoryWidget()->MoneyAmount->SetText(FText::FromString(MoneyText));

	Destroy();
}

void AMoney::BeginPlay()
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
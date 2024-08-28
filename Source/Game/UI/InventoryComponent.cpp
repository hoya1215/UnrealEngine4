// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Components/Image.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

	UTexture2D* MoneyTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Fantastic_Village_Pack/textures/T_gold_BC.T_gold_BC'"));
	//UImage* MoneyImage = CreateDefaultSubobject<UImage>(TEXT("MoneyImage"));
	//MoneyImage->SetBrushFromTexture(MoneyTexture);

	ItemImage.Add(EITEM_TYPE::MONEY, MoneyTexture);

}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::AddToInventory(EITEM_TYPE ItemType)
{
	CurrentInventory.FindOrAdd(ItemType)++;

	//return CurrentInventory.Add(Item);
}

void UInventoryComponent::RemoveFromInventory(EITEM_TYPE ItemType)
{
	//CurrentInventory.Remove(Item);
	int32 count = CurrentInventory.FindOrAdd(ItemType);
	if (count > 0)
		CurrentInventory[ItemType]--;
}

UTexture2D* UInventoryComponent::GetTexture(EITEM_TYPE ItemType)
{
	// 안전 장치 필요

	ItemImage.FindOrAdd(ItemType);
	if (ItemImage[ItemType])
		return ItemImage[ItemType];
	else
		return nullptr;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemPool.h"
#include "Item.h"
#include "Money.h"
#include "Potion.h"
#include "MyGameInstance.h"

UItemPool::UItemPool()
{
	ConstructorHelpers::FClassFinder<AMoney> MC(TEXT("Class'/Script/Game.Money'"));
	if (MC.Succeeded())
		MoneyClass = MC.Class;

	ConstructorHelpers::FClassFinder<APotion> PC(TEXT("Class'/Script/Game.Potion'"));
	if (PC.Succeeded())
		PotionClass = PC.Class;
}

void UItemPool::BeginPlay(UWorld* World)
{
	FActorSpawnParameters SpawnParams;


	CanUseItemPool.Add(FName(TEXT("Money")), MakeShareable(new TQueue<AItem*>()));
	CanUseItemPool.Add(FName(TEXT("Potion")), MakeShareable(new TQueue<AItem*>()));

	if (World)
	{
		//auto MoneyData = GameInstance->GetItemData(FName(TEXT("Money")));
		for (int i = 0; i < MaxItemCount; ++i)
		{
			AMoney* NewItem = World->SpawnActor<AMoney>(AMoney::StaticClass(), StoreLocation, FRotator::ZeroRotator, SpawnParams);
			if (NewItem)
			{
				NewItem->SetActorEnableCollision(false);
				NewItem->SetActorHiddenInGame(true);
				NewItem->SetActorTickEnabled(false);

				CanUseItemPool[FName(TEXT("Money"))]->Enqueue(NewItem);

			}


		}

		//auto PotionData = GameInstance->GetItemData(FName(TEXT("Potion")));
		for (int i = 0; i < MaxItemCount; ++i)
		{
			APotion* NewItem = World->SpawnActor<APotion>(APotion::StaticClass(), StoreLocation, FRotator::ZeroRotator, SpawnParams);
			if (NewItem)
			{
				NewItem->SetActorEnableCollision(false);
				NewItem->SetActorHiddenInGame(true);
				NewItem->SetActorTickEnabled(false);

				CanUseItemPool[FName(TEXT("Potion"))]->Enqueue(NewItem);

			}

		}
	}



}

void UItemPool::SpawnItem(FName ItemName, FVector SpawnLocation)
{


	if (CanUseItemPool[ItemName]->IsEmpty())
	{
		ReAllocatePool(ItemName);
	}




	auto SpawnedItem = *CanUseItemPool[ItemName]->Peek();
	SpawnedItem->SetActorEnableCollision(ECollisionEnabled::QueryOnly);
	SpawnedItem->SetActorHiddenInGame(false);
	SpawnedItem->SetActorTickEnabled(true);
	SpawnedItem->SetActorLocation(SpawnLocation);

	CanUseItemPool[ItemName]->Pop();
}

void UItemPool::ReturnItem(FName ItemName, AItem* ReturnedItem)
{
	ReturnedItem->SetActorLocation(StoreLocation);
	ReturnedItem->SetActorEnableCollision(false);
	ReturnedItem->SetActorHiddenInGame(true);
	ReturnedItem->SetActorTickEnabled(false);

	CanUseItemPool[ItemName]->Enqueue(ReturnedItem);
}

void UItemPool::ReAllocatePool(FName ItemName)
{
	UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	auto ItemData = GameInstance->GetItemData(ItemName);

	FActorSpawnParameters SpawnParams;

	for (int i = 0; i < SurplusItemCount; ++i)
	{
		AItem* NewItem = GetWorld()->SpawnActor<AItem>(ItemData->ItemClass, StoreLocation, FRotator::ZeroRotator, SpawnParams);
		if (NewItem)
		{
			NewItem->SetActorEnableCollision(false);
			NewItem->SetActorHiddenInGame(true);
			NewItem->SetActorTickEnabled(false);

			CanUseItemPool[ItemName]->Enqueue(NewItem);
		}
	}

}
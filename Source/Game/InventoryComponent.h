// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UImage;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	
	UTexture2D* GetTexture(EITEM_TYPE ItemType);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


public:
	UPROPERTY()
		TMap<EITEM_TYPE, int32> CurrentInventory;

	UPROPERTY()
		TMap<EITEM_TYPE, UTexture2D*> ItemImage;

	UFUNCTION()
		void AddToInventory(EITEM_TYPE ItemType);

	UFUNCTION()
		void RemoveFromInventory(EITEM_TYPE ItemType);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Clothes.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AClothes : public AItem
{
	GENERATED_BODY()
	
public:
	AClothes();

	virtual void UnEquippedItem() override;

	virtual	void OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

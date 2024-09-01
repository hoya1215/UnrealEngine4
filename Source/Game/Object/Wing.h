// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Clothes.h"
#include "Wing.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AWing : public AClothes
{
	GENERATED_BODY()

public:
	AWing();

	virtual void BeginPlay() override;
	
	virtual void EquippedItem(FItemInfo Info) override;
	virtual void UnEquippedItem() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StaticMesh;
};

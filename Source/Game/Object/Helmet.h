// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/Clothes.h"
#include "Helmet.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AHelmet : public AClothes
{
	GENERATED_BODY()
	
public:
	AHelmet();

	virtual void BeginPlay() override;

	virtual void EquippedItem(FItemInfo Info) override;
	virtual void UnEquippedItem() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY()
		UStaticMesh* HelmetStaticMesh;
};

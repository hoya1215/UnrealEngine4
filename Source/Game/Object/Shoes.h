// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/Clothes.h"
#include "Shoes.generated.h"


class UStaticMesh;

USTRUCT()
struct FShoesStat
{
	GENERATED_BODY()
};
/**
 * 
 */
UCLASS()
class GAME_API AShoes : public AClothes
{
	GENERATED_BODY()

public:
	AShoes();

	virtual void BeginPlay() override;

	virtual void EquippedItem(FItemInfo Info) override;
	virtual void UnEquippedItem() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY()
		UStaticMesh* ShoesStaticMesh;


};

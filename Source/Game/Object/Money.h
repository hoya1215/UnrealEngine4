// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Money.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AMoney : public AItem
{
	GENERATED_BODY()
	
public:
	AMoney();

	virtual void UseItem() override;

	virtual void BeginPlay() override;
public:
	UPROPERTY()
	class UStaticMeshComponent* Mesh;

	UPROPERTY()
		int32 Value;



};

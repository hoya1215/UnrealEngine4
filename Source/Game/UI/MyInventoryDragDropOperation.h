// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "MyInventoryDragDropOperation.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UMyInventoryDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()

public:
	UPROPERTY()
		class UUserWidget* InventoryWidget;

	FVector2D DragOffset;
	
};

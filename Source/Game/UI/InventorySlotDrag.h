// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "InventorySlotDrag.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UInventorySlotDrag : public UDragDropOperation
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		int SlotIndex;
};

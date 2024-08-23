// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Item.h"
#include "InventorySlotWidget.generated.h"

class UTexture2D;
/**
 * 
 */
UCLASS()
class GAME_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	// Util
	void AddItem(FName Name);

	void SetItem(UInventorySlotWidget* OtherSlot);

	//void UseItem(EITEM_TYPE ItemType);

	//void EquippedItem(AItem* Item);
	void EquippedItem(FName ItemName);

	UFUNCTION(BlueprintCallable)
		void SetSizeBox(float Width, float Height);


	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& MouseEvent,
		UDragDropOperation*& OutOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;


public:
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TSubclassOf<UInventorySlotWidget> DragVisualClass;

	UPROPERTY()
	UTexture2D* SlotTexture;

	UPROPERTY(meta = (BindWidget))
		class UImage* SlotImage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* SlotText;


	UPROPERTY(meta = (BindWidget))
		class USizeBox* SlotSizeBox;

	UPROPERTY()
		int Index;

	UPROPERTY()
		int Count = 0;

	UPROPERTY()
		class UInventoryWidget* InventoryWidget;
	

public:
	UPROPERTY()
	 AItem* CurrentItem = nullptr;

	UPROPERTY()
		FName ItemName {
		TEXT("NULL")
	};

	UPROPERTY()
		class UMyGameInstance* GameInstance;
};

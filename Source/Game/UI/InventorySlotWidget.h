// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Item.h"
#include "InventorySlotWidget.generated.h"

USTRUCT()
struct FSlotData
{
	GENERATED_BODY()

public:
	FSlotData& operator=(const FSlotData& NewData)
	{
		if (this != &NewData)
		{
			this->ItemInfo.ItemName = NewData.ItemInfo.ItemName;
			this->ItemInfo.Level = NewData.ItemInfo.Level;
			this->Count = NewData.Count;
		}
		return *this;
	}

	UPROPERTY()
		FItemInfo ItemInfo;

	UPROPERTY()
		int Count;
};

class UTexture2D;
class UItemStatWidget;
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
	void AddItem(FItemInfo ItemInfo);

	void SetItem(UInventorySlotWidget* OtherSlot);

	void ShowItemStat();

	void UpdateLevel();

	//void UseItem(EITEM_TYPE ItemType);

	//void EquippedItem(AItem* Item);
	void EquippedItem(FSlotData Data);

	UFUNCTION(BlueprintCallable)
		void SetSizeBox(float Width, float Height);


	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& MouseEvent,
		UDragDropOperation*& OutOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;


	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

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
		class UInventoryWidget* InventoryWidget;

	UPROPERTY()
		UInventorySlotWidget* CurrentSlot = nullptr;

	UPROPERTY(meta = (BindWidget))
		UItemStatWidget* ItemStatWidget;
	

public:

	UPROPERTY()
		FSlotData SlotData;

	UPROPERTY()
		class UMyGameInstance* GameInstance;
};

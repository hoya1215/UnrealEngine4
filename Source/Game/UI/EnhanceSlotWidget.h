// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlotWidget.h"
#include "EnhanceSlotWidget.generated.h"

class UEnhanceWidget;
class UMyGameInstance;
class UTexture2D;
class UImage;
/**
 * 
 */
UCLASS()
class GAME_API UEnhanceSlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	void PushItem(UInventorySlotWidget* NewSlot);
	void PullItem();
	
	void Reset();
	void UpdateText();

	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* DefaultTexture;

	UPROPERTY()
		FSlotData DefaultData;

	UPROPERTY()
		UTexture2D* SlotTexture;

	UPROPERTY(meta = (BindWidget))
		UImage* SlotImage;

	UPROPERTY()
		FSlotData SlotData;

	UPROPERTY()
		UEnhanceWidget* EnhanceWidget;

	UPROPERTY()
		UMyGameInstance* GameInstance;

	UPROPERTY()
		UInventorySlotWidget* CurrentInventorySlot;
};

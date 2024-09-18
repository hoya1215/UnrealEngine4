// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlotWidget.h"
#include "EquipmentSlotWidget.generated.h"

class AItem;
class UTexture2D;
class UTextBlock;
class UItemStatWidget;


/**
 * 
 */
UCLASS()
class GAME_API UEquipmentSlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	void PushEquipment(FSlotData Data);
	void PullEquipment();
	FSlotData SwapEquipment(FSlotData Data);

	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Texture")
	UTexture2D* DefaultSlotTexture;

	UPROPERTY()
	UTexture2D*  SlotTexture;

	UPROPERTY(meta = (BindWidget))
		class UImage* SlotImage;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* LevelText;

	UPROPERTY()
		FSlotData SlotData;

	UPROPERTY(meta = (BindWidget))
		UItemStatWidget* ItemStatWidget;

	UPROPERTY()
		class UMyGameInstance* GameInstance;
};

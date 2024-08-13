// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EquipmentSlotWidget.generated.h"

class AItem;
/**
 * 
 */
UCLASS()
class GAME_API UEquipmentSlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//UEquipmentSlotWidget(const FObjectInitializer& ObjectInitializer);

	void PushEquipment(AItem* Item, UTexture2D* Texture = nullptr);
	void PullEquipment();
	AItem* SwapEquipment(AItem* NewItem);

	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Texture")
		class UTexture2D* DefaultSlotTexture;

	UPROPERTY()
		class UTexture2D* SlotTexture;

	UPROPERTY(meta = (BindWidget))
		class UImage* SlotImage;

	UPROPERTY()
		AItem* CurrentItem;
};

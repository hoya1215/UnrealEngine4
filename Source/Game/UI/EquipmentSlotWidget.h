// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EquipmentSlotWidget.generated.h"

class AItem;
class UTexture2D;




/**
 * 
 */
UCLASS()
class GAME_API UEquipmentSlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	void PushEquipment(FName Name);
	void PullEquipment();
	FName SwapEquipment(FName NewName);

	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Texture")
	UTexture2D* DefaultSlotTexture;

	UPROPERTY()
	UTexture2D*  SlotTexture;

	UPROPERTY(meta = (BindWidget))
		class UImage* SlotImage;

	UPROPERTY()
		AItem* CurrentItem;

	UPROPERTY()
		FName ItemName {TEXT("NULL") };

	UPROPERTY()
		class UMyGameInstance* GameInstance;
};

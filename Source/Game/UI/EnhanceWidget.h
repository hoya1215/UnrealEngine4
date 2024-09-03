// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnhanceWidget.generated.h"

class UEnhanceSlotWidget;
class UTextBlock;
class UButton;
class AMyCharacter;
/**
 * 
 */
UCLASS()
class GAME_API UEnhanceWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UEnhanceWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UFUNCTION()
	void ClickUpgradeButton();

	void UpdateEnhancePoint();

public:
	

	UPROPERTY()
		TSubclassOf<UEnhanceSlotWidget> EnhanceSlotWidgetClass;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* EnhancePoint;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentLevel;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* NextLevel;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* CompareText1;


	UPROPERTY(meta = (BindWidget))
		UEnhanceSlotWidget* ItemSlot;

	UPROPERTY(meta = (BindWidget))
		UButton* UpgradeButton;

	// Default
	UPROPERTY()
		FString DefaultText;

	UPROPERTY()
		FString CompareText;

	UPROPERTY()
		int MaxItemLevel = 5;


private:
	UPROPERTY()
		AMyCharacter* MyCharacter;
};

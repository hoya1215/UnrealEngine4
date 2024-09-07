// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AbilityWidget.generated.h"

class AMyCharacter;
class UTextBlock;
/**
 * 
 */
UCLASS()
class GAME_API UAbilityWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetAbilityText();

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UPROPERTY(meta = (BindWidget))
		UTextBlock* PowerText;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* HpText;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* DefenseText;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* SpeedText;


private:
	AMyCharacter* MyCharacter;
};

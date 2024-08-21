// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyHUD.generated.h"

class UTextBlock;
class UProgressBar;
class UImage;
class AMyCharacter;

/**
 * 
 */
UCLASS()
class GAME_API UMyHUD : public UUserWidget
{
	GENERATED_BODY()

public:


	virtual void NativeConstruct() override;

	void UpdateHp();
	void UpdateWeaponImage();

	void SetCharacter(AMyCharacter* CurrentCharacter);

public:
	UPROPERTY(Meta = (BindWidget))
	UTextBlock* BulletText;

	UPROPERTY(Meta = (BindWidget))
		UTextBlock* HpText;

	UPROPERTY(Meta = (BindWidget))
		UProgressBar* Hp_Bar;

	UPROPERTY(Meta = (BindWidget))
		UImage* CurrentWeapon;

	UPROPERTY()
		UTexture2D* DefaultTexture;

private:
	UPROPERTY()
		AMyCharacter* MyCharacter;
};

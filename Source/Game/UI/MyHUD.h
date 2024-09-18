// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyHUD.generated.h"

class UTextBlock;
class UProgressBar;
class UImage;
class AMyCharacter;
class USkillSlotWidget;
class UAcquireWidget;

/**
 * 
 */
DECLARE_MULTICAST_DELEGATE(FAcquireWidgetUp)
UCLASS()
class GAME_API UMyHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UMyHUD(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	

	void UpdateHp();
	void UpdateExp(float ExpRatio);
	void UpdateLevel(int Level);
	void UpdateWeaponImage();

	void AcquireItem(FName ItemName);
	void SwapAcquireWidget();

	void SetCharacter(AMyCharacter* CurrentCharacter);

	FAcquireWidgetUp AcquireWidgetUp;

public:
	//UPROPERTY(Meta = (BindWidget))
	//UTextBlock* BulletText;

	UPROPERTY(Meta = (BindWidget))
		UTextBlock* HpText;

	UPROPERTY(Meta = (BindWidget))
		UProgressBar* Hp_Bar;

	UPROPERTY(Meta = (BindWidget))
		UProgressBar* Exp_Bar;

	UPROPERTY(Meta = (BindWidget))
		UTextBlock* ExpText;

	UPROPERTY(Meta = (BindWidget))
		UTextBlock* LevelText;

	UPROPERTY(Meta = (BindWidget))
		UImage* CurrentWeapon;

	UPROPERTY()
		UTexture2D* DefaultTexture;

	// Skill
	UPROPERTY(Meta = (BindWidget))
		USkillSlotWidget* TabSkill;

private:
	UPROPERTY()
		AMyCharacter* MyCharacter;



	UPROPERTY()
		TSubclassOf<UAcquireWidget> AcquireWidgetClass;

	UPROPERTY(meta = (BindWidget))
		UAcquireWidget* AcquireWidgetTop;

	UPROPERTY(meta = (BindWidget))
		UAcquireWidget* AcquireWidgetMiddle;

	UPROPERTY(meta = (BindWidget))
		UAcquireWidget* AcquireWidgetBottom;

	TQueue<UAcquireWidget*> AcquireWidgets;
	int MaxAcquireWidgetCount = 3;
};

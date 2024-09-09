// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillSlotWidget.generated.h"

class UProgressBar;
class UTextBlock;
class USkill;
/**
 * 
 */
UCLASS()
class GAME_API USkillSlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

	void SetProgressBarImage(UTexture2D* Texture);
	void SetSkill(USkill* NewSkill);

public:
	UPROPERTY(meta = (BindWidget))
		UProgressBar* Skill_Bar;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* Time;

	UPROPERTY()
		USkill* Skill;

	float CoolTime = 0.f;
	float CurrentTime = 0.f;
};

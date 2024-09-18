// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AcquireWidget.generated.h"

class UImage;
class UTexture2D;
class UWidgetAnimation;
class UCanvasPanel;
/**
 * 
 */
UCLASS()
class GAME_API UAcquireWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	void AcquireItem(UTexture2D* ItemTexture, bool Animation = true, float Time = 0.f);
	void Up();

	void Disappear();

public:
	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* Panel;

	UPROPERTY()
		UTexture2D* Texture;

	UPROPERTY(meta = (BindWidget))
		UImage* ItemImage;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
		UWidgetAnimation* Appear;

	FTimerHandle DisappearTimer;
	float DisappearTime = 0.f;

	FVector2D CurrentPosition{ 1950.f, 400.f };
	FVector2D StartPosition{ 1950.f, 400.f };
	float Interval = 120.f;
};

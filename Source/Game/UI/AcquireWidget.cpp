// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AcquireWidget.h"
#include "Components/Image.h"
#include "Components/CanvasPanel.h"



void UAcquireWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (DisappearTime > 0.f)
	{
		DisappearTime += InDeltaTime;
		if (DisappearTime >= 2.f)
		{
			Disappear();
		}
	}


}

void UAcquireWidget::AcquireItem(UTexture2D* ItemTexture, bool Animation, float Time)
{
	Texture = ItemTexture;
	ItemImage->SetBrushFromTexture(ItemTexture);
	// 보이게 하고 timer 설정해서 다시 안보이게
	SetVisibility(ESlateVisibility::Visible);

	if (Animation)
	{
		PlayAnimation(Appear);
		//GetWorld()->GetTimerManager().SetTimer(DisappearTimer, this, &UAcquireWidget::Disappear, DisappearTime, true);
	}


	DisappearTime = Time;
}

void UAcquireWidget::Up()
{
	CurrentPosition.Y -= Interval;
	SetPositionInViewport(CurrentPosition);
}

void UAcquireWidget::Disappear()
{
	SetVisibility(ESlateVisibility::Hidden);
	Texture = nullptr;
	DisappearTime = 0.f;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SkillSlotWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Slate/SlateBrushAsset.h"
#include "Skill.h"


void USkillSlotWidget::SetProgressBarImage(UTexture2D* Texture)
{

    FSlateBrush NewBackgroundBrush = Skill_Bar->WidgetStyle.BackgroundImage;
    NewBackgroundBrush.SetResourceObject(Texture); 
    //NewBackgroundBrush.ImageSize = FVector2D(Texture->GetSizeX(), Texture->GetSizeY()); 



    Skill_Bar->WidgetStyle.BackgroundImage = NewBackgroundBrush;

    Skill_Bar->SynchronizeProperties();
}

void USkillSlotWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
    float Ratio = 0.f;
    FString T = FString::Printf(TEXT(""));

    if (CurrentTime > 0.f)
    {
        CurrentTime += InDeltaTime;
        Ratio = (CoolTime - CurrentTime) / CoolTime;
        T = FString::Printf(TEXT("%.1f"), (CoolTime - CurrentTime));
    }

    if (CurrentTime >= CoolTime)
    {
        CurrentTime = 0.f;
    }


    Skill_Bar->SetPercent(Ratio);
    Time->SetText(FText::FromString(T));
}

void USkillSlotWidget::SetSkill(USkill* NewSkill)
{
    Skill = NewSkill;
    CoolTime = NewSkill->CoolTime;

    SetProgressBarImage(NewSkill->SkillTexture);
}



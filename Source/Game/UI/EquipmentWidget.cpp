// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentWidget.h"
#include "AbilityWidget.h"
#include "Components/Button.h"

UEquipmentWidget::UEquipmentWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    static ConstructorHelpers::FClassFinder<UEquipmentSlotWidget> ES(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_EquipSlot.WBP_EquipSlot_C'"));
    if (ES.Succeeded())
        EquipmentSlotWidgetClass = ES.Class;
}

void UEquipmentWidget::NativeConstruct()
{
    Super::NativeConstruct();

    InitSlots();

    if (AbilityButton)
    {
        AbilityButton->OnClicked.AddDynamic(this, &UEquipmentWidget::ClickAbilityButton);
    }

    AbilityWidget->SetVisibility(ESlateVisibility::Hidden);
}

void UEquipmentWidget::ClickAbilityButton()
{
    ESlateVisibility Ability_Visibility = AbilityWidget->GetVisibility();
    if (Ability_Visibility == ESlateVisibility::Visible)
    {
        AbilityWidget->SetVisibility(ESlateVisibility::Hidden);
    }
    else
    {
        AbilityWidget->SetVisibility(ESlateVisibility::Visible);
    }

}

void UEquipmentWidget::InitSlots()
{
    EquipmentSlots.Add(EEQUIPMENT_TYPE::MAIN, MainWeaponSlot);
    EquipmentSlots.Add(EEQUIPMENT_TYPE::SUB, SubWeaponSlot);
    EquipmentSlots.Add(EEQUIPMENT_TYPE::OTHER, OtherWeaponSlot);
    EquipmentSlots.Add(EEQUIPMENT_TYPE::WING, WingSlot);
    EquipmentSlots.Add(EEQUIPMENT_TYPE::SHOES, ShoesSlot);
    EquipmentSlots.Add(EEQUIPMENT_TYPE::HELMET, HelmetSlot);
}


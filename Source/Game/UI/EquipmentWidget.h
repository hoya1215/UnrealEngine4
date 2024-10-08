// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Item.h"
#include "EquipmentSlotWidget.h"
#include "EquipmentWidget.generated.h"


class UImage;
class UUniformGridPanel;
class USizeBox;
class UButton;
class UAbilityWidget;

/**
 * 
 */
UCLASS()
class GAME_API UEquipmentWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UEquipmentWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UFUNCTION()
	void ClickAbilityButton();

	void InitSlots();

	UPROPERTY(meta = (BindWidget))
		UUniformGridPanel* LeftPanel;

	UPROPERTY(meta = (BindWidget))
		UUniformGridPanel* RightPanel;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
		TSubclassOf<UEquipmentSlotWidget> EquipmentSlotWidgetClass;

	UPROPERTY()
		TMap<EEQUIPMENT_TYPE, UEquipmentSlotWidget*> EquipmentSlots;

	UPROPERTY(meta = (BindWidget))
		UAbilityWidget* AbilityWidget;

private:
	UPROPERTY(meta = (BindWidget))
		UButton* AbilityButton;



	// ����
	UPROPERTY(meta = (BindWidget))
		UEquipmentSlotWidget* WingSlot;


	UPROPERTY(meta = (BindWidget))
		UEquipmentSlotWidget* ShoesSlot;

	UPROPERTY(meta = (BindWidget))
		UEquipmentSlotWidget* HelmetSlot;

	UPROPERTY(meta = (BindWidget))
		UEquipmentSlotWidget* MainWeaponSlot;

	UPROPERTY(meta = (BindWidget))
		UEquipmentSlotWidget* SubWeaponSlot;

	UPROPERTY(meta = (BindWidget))
		UEquipmentSlotWidget* OtherWeaponSlot;
	
};

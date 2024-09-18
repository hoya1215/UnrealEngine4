// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIManager.generated.h"

class AMyCharacter;
class UInventoryComponent;
class UInventoryWidget;
class UEquipmentWidget;
class UEnhanceWidget;
class UMyHUD;
/**
 * 
 */
UCLASS()
class GAME_API UUIManager : public UObject
{
	GENERATED_BODY()

public:
	static UUIManager* Get();

	void BeginPlay(AMyCharacter* Character);

	void OpenInventory();
	void OpenEquipment();
	void OpenEnhance();

	UMyHUD* GetHUD() { return HUD; }
	UInventoryWidget* GetInventoryWidget() { return InventoryWidget; }
	UEquipmentWidget* GetEquipmentWidget() { return EquipmentWidget; }
	UEnhanceWidget* GetEnhanceWidget() { return EnhanceWidget; }

	int GetPresentUICount() { return PresentUICount; }

private:
	UUIManager();

	static UUIManager* UIManager;

	// HUD
	UPROPERTY()
		UMyHUD* HUD;

	UPROPERTY()
		TSubclassOf<UMyHUD> HUDClass;
	
	// Inventory
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> InventoryWidgetClass;
	UPROPERTY()
	UInventoryWidget* InventoryWidget;

	// Equipment
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> EquipmentWidgetClass;
	UPROPERTY()
	UEquipmentWidget* EquipmentWidget;

	// Enhance
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UEnhanceWidget> EnhanceWidgetClass;
	UPROPERTY()
	UEnhanceWidget* EnhanceWidget;

	UPROPERTY()
	UWorld* World;

	UPROPERTY()
		AMyCharacter* MyCharacter;

	int PresentUICount = 0;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Item.h"
#include "InventoryWidget.generated.h"

class UImage;
class UInventorySlotWidget;
class UUniformGridPanel;
class USizeBox;
class UButton;
class UTextBlock;

/**
 * 
 */
DECLARE_MULTICAST_DELEGATE(FClickTop)
UCLASS()
class GAME_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    FClickTop ClickTop;

    UInventoryWidget(const FObjectInitializer& ObjectInitializer);

    virtual void NativeConstruct() override;
    virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& MouseEvent,
        UDragDropOperation*& Operation) override;
    //virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
    //virtual bool NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, 
    //    UDragDropOperation* InOperation) override;

    //virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    //virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    //virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;


    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Inventory")
        void AddItemToInventory(FName Name);

    void Init();

    void SwapSlot(int From, int To);
    
    void CreateSlot();

    void FillInventory(TArray < UInventorySlotWidget*> before, TArray<UInventorySlotWidget*> after);
    void SwapInventory(EINVENTORY_TYPE InventoryType);

    UFUNCTION()
    void ClickEquipmentButton();

    UFUNCTION()
    void ClickConsumptionButton();

    UFUNCTION()
    void ClickEtcButton();
    //virtual void NativeConstruct() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Texture")
        class UTexture2D* DefaultSlotTexture;


    UPROPERTY()
        UInventorySlotWidget* DefaultSlot;

    UPROPERTY()
        int32 CurrentMoney;

    UPROPERTY(meta = (BindWidget))
        UTextBlock* MoneyAmount;

protected:
    

    //UPROPERTY(meta = (BindWidget))
    //    UUniformGridPanel* InventoryBoard;


    //UPROPERTY(meta = (BindWidget))
    //    USizeBox* TopSizeBox;

    //UPROPERTY(meta = (BindWidget))
    //USizeBox* InventorySizeBox;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
        TSubclassOf<UInventorySlotWidget> InventorySlotWidgetClass;

    UPROPERTY(meta = (BindWidget))
        UButton* EquipmentButton;

    UPROPERTY(meta = (BindWidget))
        UButton* ConsumptionButton;

    UPROPERTY(meta = (BindWidget))
        UButton* EtcButton;

    // Slots
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot0;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot1;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot2;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot3;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot4;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot5;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot6;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot7;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot8;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot9;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot10;
    UPROPERTY(meta = (BindWidget))
        UInventorySlotWidget* Slot11;




public:
    TArray<UInventorySlotWidget*> CurrentSlotWidgets;
    TArray<UInventorySlotWidget*> EquipmentSlotWidgets;
    TArray<UInventorySlotWidget*> ConsumptionSlotWidgets;
    TArray<UInventorySlotWidget*> ETCSlotWidgets;

    int32 CurrentSlotIndex_Equipment = 0;
    int32 CurrentSlotIndex_Consumption = 0;
    int32 CurrentSlotIndex_Etc = 0;
    int32 MaxInventorySize = 12;

    int32 InventoryState = 0; // 0 : Equipment  , 1 : Consumption ,  2 : Etc

    bool bIsDragging = false;
    FVector2D DragOffset;

    UPROPERTY()
        class UMyGameInstance* GameInstance;
	
};

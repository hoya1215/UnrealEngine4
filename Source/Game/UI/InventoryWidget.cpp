// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "Components/UniformGridPanel.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlotWidget.h"
#include "Components/SizeBox.h"
#include "Components/UniformGridSlot.h"
#include "MyInventoryDragDropOperation.h"
#include "Components/Image.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/TextBlock.h"
#include "Item.h"
#include "Components/Button.h"
#include "MyGameInstance.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    static ConstructorHelpers::FClassFinder<UInventorySlotWidget> IS(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_Slot.WBP_Slot_C'"));
    if (IS.Succeeded())
        InventorySlotWidgetClass = IS.Class;

}

void UInventoryWidget::NativeConstruct()
{
    Super::NativeConstruct();

    GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
    // Default Slot , Push
    DefaultSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
    DefaultSlot->SlotTexture = DefaultSlotTexture;
    FSlotData DefaultData;
    DefaultData.ItemInfo.ItemName = FName(TEXT("NULL"));
    DefaultData.ItemInfo.Level = 0;
    DefaultData.Count = 0;
    DefaultSlot->SlotData = DefaultData;
    DefaultSlot->GameInstance = this->GameInstance;

    Init();
    //InventoryBoard->ClearChildren();
    //CurrentSlotWidgets.Empty();

    //CreateSlot();
    //FillInventory(EquipmentSlotWidgets);

    if (EquipmentButton)
    {
        EquipmentButton->OnClicked.AddDynamic(this, &UInventoryWidget::ClickEquipmentButton);
    }

    if (ConsumptionButton)
    {
        ConsumptionButton->OnClicked.AddDynamic(this, &UInventoryWidget::ClickConsumptionButton);
    }

    if (EtcButton)
    {
        EtcButton->OnClicked.AddDynamic(this, &UInventoryWidget::ClickEtcButton);
    }

    GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

}

void UInventoryWidget::Init()
{
    // Current Slot
    CurrentSlotWidgets.Add(Slot0);
    CurrentSlotWidgets.Add(Slot1);
    CurrentSlotWidgets.Add(Slot2);
    CurrentSlotWidgets.Add(Slot3);
    CurrentSlotWidgets.Add(Slot4);
    CurrentSlotWidgets.Add(Slot5);
    CurrentSlotWidgets.Add(Slot6);
    CurrentSlotWidgets.Add(Slot7);
    CurrentSlotWidgets.Add(Slot8);
    CurrentSlotWidgets.Add(Slot9);
    CurrentSlotWidgets.Add(Slot10);
    CurrentSlotWidgets.Add(Slot11);

    for (int i = 0; i < MaxInventorySize; ++i)
    {
        CurrentSlotWidgets[i]->Index = i;
        CurrentSlotWidgets[i]->InventoryWidget = this;
        CurrentSlotWidgets[i]->GameInstance = this->GameInstance;
        CurrentSlotWidgets[i]->SetItem(DefaultSlot);
    }

    // Equipment
    for (int i = 0; i < MaxInventorySize; ++i)
    {
        UInventorySlotWidget* NewSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
        NewSlot->Index = i;
        NewSlot->InventoryWidget = this;
        NewSlot->GameInstance = this->GameInstance;
        NewSlot->CurrentSlot = CurrentSlotWidgets[i];
        NewSlot->SetItem(DefaultSlot);
        

        EquipmentSlotWidgets.Add(NewSlot);
    }

    // Consumption
    for (int i = 0; i < MaxInventorySize; ++i)
    {
        UInventorySlotWidget* NewSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
        NewSlot->Index = i;
        NewSlot->InventoryWidget = this;
        NewSlot->GameInstance = this->GameInstance;
        NewSlot->SetItem(DefaultSlot);

        ConsumptionSlotWidgets.Add(NewSlot);
    }

    // ETC
    for (int i = 0; i < MaxInventorySize; ++i)
    {
        UInventorySlotWidget* NewSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
        NewSlot->Index = i;
        NewSlot->InventoryWidget = this;
        NewSlot->GameInstance = this->GameInstance;
        NewSlot->SetItem(DefaultSlot);

        ETCSlotWidgets.Add(NewSlot);
    }

    //FillInventory(EquipmentSlotWidgets, CurrentSlotWidgets);
}


void UInventoryWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& MouseEvent, UDragDropOperation*& Operation)
{
    Super::NativeOnDragDetected(InGeometry, MouseEvent, Operation);

    UMyInventoryDragDropOperation* DragDropOp = NewObject<UMyInventoryDragDropOperation>(this);
    DragDropOp->DefaultDragVisual = this; // 드래그 중에 보여질 위젯
    DragDropOp->Pivot = EDragPivot::CenterCenter;

    // 드래그 시작 시의 상대적 위치 저장
    DragDropOp->InventoryWidget = this;
    DragDropOp->DragOffset = MouseEvent.GetScreenSpacePosition() - InGeometry.GetAbsolutePosition();

    Operation = DragDropOp;
}


void UInventoryWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

}


void UInventoryWidget::AddItemToInventory(FItemInfo ItemInfo)
{
    if (InventorySlotWidgetClass)
    {


        switch (GameInstance->GetItemData(ItemInfo.ItemName)->InventoryType)
        {
        case EINVENTORY_TYPE::EQUIPMENT:
            if (CurrentSlotIndex_Equipment < MaxInventorySize)
            {
                for (int i = 0; i < EquipmentSlotWidgets.Num(); ++i)
                {
                    if (EquipmentSlotWidgets[i]->SlotData.ItemInfo.ItemName == FName("NULL"))
                    {
                        EquipmentSlotWidgets[i]->AddItem(ItemInfo);
                        break;
                    }
                }

            }
            break;
        case EINVENTORY_TYPE::CONSUMPTION:
            if (CurrentSlotIndex_Consumption < MaxInventorySize)
            {
                bool bNew = true;

                for (int i = 0; i < ConsumptionSlotWidgets.Num(); ++i)
                {
                    if (ConsumptionSlotWidgets[i]->SlotData.ItemInfo.ItemName == ItemInfo.ItemName)
                    {
                        ConsumptionSlotWidgets[i]->AddItem(ItemInfo);
                        bNew = false;
                        break;
                    }
                }

                if (bNew)
                {
                    for (int i = 0; i < ConsumptionSlotWidgets.Num(); ++i)
                    {
                        if (ConsumptionSlotWidgets[i]->SlotData.ItemInfo.ItemName == FName(TEXT("NULL")))
                        {
                            ConsumptionSlotWidgets[i]->AddItem(ItemInfo);
                            break;
                        }
                    }
                }

            }
            break;
        case EINVENTORY_TYPE::ETC:
            if (CurrentSlotIndex_Etc < MaxInventorySize)
            {
                for (int i = 0; i < ETCSlotWidgets.Num(); ++i)
                {
                    if (ETCSlotWidgets[i]->SlotData.ItemInfo.ItemName == FName(TEXT("NULL")))
                    {
                        ETCSlotWidgets[i]->AddItem(ItemInfo);
                        break;
                    }
                }

            }
            break;
        }
    }
}

void UInventoryWidget::SwapSlot(int From, int To)
{
    UInventorySlotWidget* Copy = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
    
    switch (InventoryState)
    {
    case 0:
        Copy->SetItem(EquipmentSlotWidgets[From]);
        EquipmentSlotWidgets[From]->SetItem(EquipmentSlotWidgets[To]);
        EquipmentSlotWidgets[To]->SetItem(Copy);
        break;
    case 1:
        Copy->SetItem(ConsumptionSlotWidgets[From]);
        ConsumptionSlotWidgets[From]->SetItem(ConsumptionSlotWidgets[To]);
        ConsumptionSlotWidgets[To]->SetItem(Copy);
        break;
    case 2:
        Copy->SetItem(ETCSlotWidgets[From]);
        ETCSlotWidgets[From]->SetItem(ETCSlotWidgets[To]);
        ETCSlotWidgets[To]->SetItem(Copy);
        break;
    }
    
    //Copy->SetItem(CurrentSlotWidgets[From]);
    //
    //
    //CurrentSlotWidgets[From]->SetItem(CurrentSlotWidgets[To]);
    //CurrentSlotWidgets[To]->SetItem(Copy);


}

void UInventoryWidget::CreateSlot()
{

    //int32 Row = 4;
    //int32 Column = 4;

    //float Width = InventorySizeBox->WidthOverride;
    //float Height = InventorySizeBox->HeightOverride;

    //DefaultSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
    //DefaultSlot->SlotTexture = DefaultSlotTexture;
    //DefaultSlot->ItemName = FName(TEXT("NULL"));

    //for (int32 i = 0; i < Row; ++i)
    //{
    //    for (int32 j = 0; j < Column; ++j)
    //    {
    //        UInventorySlotWidget* NewSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
    //        NewSlot->SetSizeBox(Width / Row, Height / Column);
    //        NewSlot->Index = i * Row + j;
    //        NewSlot->InventoryWidget = this;
    //        NewSlot->SetItem(DefaultSlot);

    //        EquipmentSlotWidgets.Add(NewSlot);

    //    }
    //}

    //for (int32 i = 0; i < Row; ++i)
    //{
    //    for (int32 j = 0; j < Column; ++j)
    //    {
    //        UInventorySlotWidget* NewSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
    //        NewSlot->SetSizeBox(Width / Row, Height / Column);
    //        NewSlot->Index = i * Row + j;
    //        NewSlot->InventoryWidget = this;
    //        NewSlot->SetItem(DefaultSlot);

    //        ConsumptionSlotWidgets.Add(NewSlot);

    //    }
    //}

    //for (int32 i = 0; i < Row; ++i)
    //{
    //    for (int32 j = 0; j < Column; ++j)
    //    {
    //        UInventorySlotWidget* NewSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
    //        NewSlot->SetSizeBox(Width / Row, Height / Column);
    //        NewSlot->Index = i * Row + j;
    //        NewSlot->InventoryWidget = this;
    //        NewSlot->SetItem(DefaultSlot);

    //        ETCSlotWidgets.Add(NewSlot);

    //    }
    //}

    
}

void UInventoryWidget::FillInventory(TArray < UInventorySlotWidget*> before, TArray<UInventorySlotWidget*> after)
{

    for (int i = 0; i < MaxInventorySize; ++i)
    {
        //after[i]->SetItem(before[i]);
        after[i] = before[i];
    }

    //InventoryBoard->ClearChildren();
    //CurrentSlotWidgets.Empty();

    //int32 Row = 4;
    //int32 Column = 4;


    //for (int32 i = 0; i < Row; ++i)
    //{
    //    for (int32 j = 0; j < Column; ++j)
    //    {
    //        int Index = i * Row + j;

    //    

    //        if (Index < EquipmentSlotWidgets.Num())
    //        {              
    //            InventoryBoard->AddChildToUniformGrid(Slots[Index], i, j);
    //        } 
    //    }
    //}

    //CurrentSlotWidgets = Slots;
}

void UInventoryWidget::SwapInventory(EINVENTORY_TYPE InventoryType)
{
    switch (InventoryState)
    {
    case 0:
        for (int i = 0; i < MaxInventorySize; ++i)
        {
            EquipmentSlotWidgets[i]->SetItem(CurrentSlotWidgets[i]);
            EquipmentSlotWidgets[i]->CurrentSlot = nullptr;

        }
        break;
    case 1:
        for (int i = 0; i < MaxInventorySize; ++i)
        {
            ConsumptionSlotWidgets[i]->SetItem(CurrentSlotWidgets[i]);
            ConsumptionSlotWidgets[i]->CurrentSlot = nullptr;

        }
        break;
    case 2:
        for (int i = 0; i < MaxInventorySize; ++i)
        {
            ETCSlotWidgets[i]->SetItem(CurrentSlotWidgets[i]);
            ETCSlotWidgets[i]->CurrentSlot = nullptr;

        }
        break;
    }

    switch (InventoryType)
    {
    case EINVENTORY_TYPE::EQUIPMENT:
        InventoryState = 0;
        for (int i = 0; i < MaxInventorySize; ++i)
        {
            CurrentSlotWidgets[i]->SetItem(EquipmentSlotWidgets[i]);
            EquipmentSlotWidgets[i]->CurrentSlot = CurrentSlotWidgets[i];
        }
        break;
    case EINVENTORY_TYPE::CONSUMPTION:
        InventoryState = 1;
        for (int i = 0; i < MaxInventorySize; ++i)
        {
            CurrentSlotWidgets[i]->SetItem(ConsumptionSlotWidgets[i]);
            ConsumptionSlotWidgets[i]->CurrentSlot = CurrentSlotWidgets[i];
        }
        break;
    case EINVENTORY_TYPE::ETC:
        InventoryState = 2;
        for (int i = 0; i < MaxInventorySize; ++i)
        {
            CurrentSlotWidgets[i]->SetItem(ETCSlotWidgets[i]);
            ETCSlotWidgets[i]->CurrentSlot = CurrentSlotWidgets[i];
        }
        break;
    }

    //switch (InventoryState)
    //{
    //case 0:
    //    FillInventory(CurrentSlotWidgets, EquipmentSlotWidgets);
    //    //EquipmentSlotWidgets = CurrentSlotWidgets;
    //    break;
    //case 1:
    //    FillInventory(CurrentSlotWidgets, ConsumptionSlotWidgets);
    //    //ConsumptionSlotWidgets = CurrentSlotWidgets;
    //    break;
    //case 2:
    //    FillInventory(CurrentSlotWidgets, ETCSlotWidgets);
    //    //ETCSlotWidgets = CurrentSlotWidgets;
    //    break;
    //}

    //switch (InventoryType)
    //{
    //case EINVENTORY_TYPE::EQUIPMENT:
    //    FillInventory(EquipmentSlotWidgets, CurrentSlotWidgets);
    //    InventoryState = 0;
    //    break;
    //case EINVENTORY_TYPE::CONSUMPTION:
    //    FillInventory(ConsumptionSlotWidgets, CurrentSlotWidgets);
    //    InventoryState = 1;
    //    break;
    //case EINVENTORY_TYPE::ETC:
    //    FillInventory(ETCSlotWidgets, CurrentSlotWidgets);
    //    InventoryState = 2;
    //    break;
    //}
}

void UInventoryWidget::ClickEquipmentButton()
{
    if (InventoryState == 0)
        return;

    SwapInventory(EINVENTORY_TYPE::EQUIPMENT);
}

void UInventoryWidget::ClickConsumptionButton()
{
    if (InventoryState == 1)
        return;

    SwapInventory(EINVENTORY_TYPE::CONSUMPTION);
}

void UInventoryWidget::ClickEtcButton()
{
    if (InventoryState == 2)
        return;

    SwapInventory(EINVENTORY_TYPE::ETC);
}

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

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    static ConstructorHelpers::FClassFinder<UInventorySlotWidget> IS(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_Slot.WBP_Slot_C'"));
    if (IS.Succeeded())
        InventorySlotWidgetClass = IS.Class;

}

void UInventoryWidget::NativeConstruct()
{
    Super::NativeConstruct();

    InventoryBoard->ClearChildren();
    SlotWidgets.Empty();

    CreateSlot();
    FillInventory(EquipmentSlotWidgets);

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



//FReply UInventoryWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
//{
//    FEventReply Reply;
//    Reply.NativeReply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
//
//
//    if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
//    {
//        bIsDragging = true;
//        DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
//        //Reply = UWidgetBlueprintLibrary::CaptureMouse(Reply, TopSizeBox);
//        //return Reply.NativeReply;
//        return FReply::Handled().CaptureMouse(AsShared());
//    }
//
//
//    return Reply.NativeReply;
//}
//
//FReply UInventoryWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
//{
//    FEventReply Reply;
//    Reply.NativeReply = Super::NativeOnMouseMove(InGeometry, InMouseEvent);
//
//    if (bIsDragging)
//    {
//        FVector2D NewPosition = InMouseEvent.GetScreenSpacePosition() - DragOffset;
//        SetPositionInViewport(NewPosition, false);
//        return FReply::Handled();
//    }
//    return FReply::Unhandled();
//    //return Reply.NativeReply;
//}
//
//
//FReply UInventoryWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
//{
//    FEventReply Reply;
//    Reply.NativeReply = Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);
//
//    if (bIsDragging && InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
//    {
//        bIsDragging = false;
//        //Reply = UWidgetBlueprintLibrary::ReleaseMouseCapture(Reply);
//        //return Reply.NativeReply;
//        return FReply::Handled().ReleaseMouseCapture();
//    }
//
//    return Reply.NativeReply;
//}

void UInventoryWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    //if (bIsDragging)
    //{
    //    FVector2D MousePosition;
    //    if (GetWorld()->GetFirstPlayerController()->GetMousePosition(MousePosition.X, MousePosition.Y))
    //    {
    //        FVector2D NewPosition = MousePosition - DragOffset;
    //        SetPositionInViewport(NewPosition, false);
    //    }
    //}
}


void UInventoryWidget::AddItemToInventory(AItem* Item)
{
    if (InventorySlotWidgetClass)
    {
        switch (Item->InventoryType)
        {
        case EINVENTORY_TYPE::EQUIPMENT:
            if (CurrentSlotIndex_Equipment < MaxInventorySize)
            {
                for (int i = 0; i < EquipmentSlotWidgets.Num(); ++i)
                {
                    if (EquipmentSlotWidgets[i]->SlotItem == nullptr)
                    {
                        EquipmentSlotWidgets[i]->AddItem(Item);
                        break;
                    }
                }
                //EquipmentSlotWidgets[CurrentSlotIndex_Equipment]->AddItem(Item);
                //CurrentSlotIndex_Equipment++;
            }
            break;
        case EINVENTORY_TYPE::CONSUMPTION:
            if (CurrentSlotIndex_Consumption < MaxInventorySize)
            {
                for (int i = 0; i < ConsumptionSlotWidgets.Num(); ++i)
                {
                    if (ConsumptionSlotWidgets[i]->SlotItem == nullptr)
                    {
                        ConsumptionSlotWidgets[i]->AddItem(Item);
                        break;
                    }
                }
                //ConsumptionSlotWidgets[CurrentSlotIndex_Consumption]->AddItem(Item);
                //CurrentSlotIndex_Consumption++;
            }
            break;
        case EINVENTORY_TYPE::ETC:
            if (CurrentSlotIndex_Etc < MaxInventorySize)
            {
                for (int i = 0; i < ETCSlotWidgets.Num(); ++i)
                {
                    if (ETCSlotWidgets[i]->SlotItem == nullptr)
                    {
                        ETCSlotWidgets[i]->AddItem(Item);
                        break;
                    }
                }
                //ETCSlotWidgets[CurrentSlotIndex_Etc]->AddItem(Item);
                //CurrentSlotIndex_Etc++;
            }
            break;
        }
    }
}

void UInventoryWidget::SwapSlot(int From, int To)
{
    UInventorySlotWidget* Copy = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
    Copy->SetItem(SlotWidgets[From]);
    UTexture2D* Tex = SlotWidgets[From]->SlotTexture;
    //SlotWidgets[From] = SlotWidgets[To];
    //SlotWidgets[From]->Index = From;

        SlotWidgets[From]->SetItem(SlotWidgets[To]);
        SlotWidgets[To]->SetItem(Copy);

        //switch (InventoryState)
        //{
        //case 0:
        //    EquipmentSlotWidgets[From]->SetItem(EquipmentSlotWidgets[To]);
        //    EquipmentSlotWidgets[To]->SetItem(Copy);
        //    break;
        //case 1:
        //    ConsumptionSlotWidgets[From]->SetItem(ConsumptionSlotWidgets[To]);
        //    ConsumptionSlotWidgets[To]->SetItem(Copy);
        //    break;
        //case 2:
        //    ETCSlotWidgets[From]->SetItem(ETCSlotWidgets[To]);
        //    ETCSlotWidgets[To]->SetItem(Copy);
        //    break;
        //}

}

void UInventoryWidget::CreateSlot()
{

    int32 Row = 4;
    int32 Column = 4;

    float Width = InventorySizeBox->WidthOverride;
    float Height = InventorySizeBox->HeightOverride;

    DefaultSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
    DefaultSlot->SlotTexture = DefaultSlotTexture;

    for (int32 i = 0; i < Row; ++i)
    {
        for (int32 j = 0; j < Column; ++j)
        {
            UInventorySlotWidget* NewSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
            NewSlot->SetSizeBox(Width / Row, Height / Column);
            NewSlot->Index = i * Row + j;
            NewSlot->InventoryWidget = this;
            NewSlot->SetItem(DefaultSlot);

            EquipmentSlotWidgets.Add(NewSlot);

        }
    }

    for (int32 i = 0; i < Row; ++i)
    {
        for (int32 j = 0; j < Column; ++j)
        {
            UInventorySlotWidget* NewSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
            NewSlot->SetSizeBox(Width / Row, Height / Column);
            NewSlot->Index = i * Row + j;
            NewSlot->InventoryWidget = this;
            NewSlot->SetItem(DefaultSlot);

            ConsumptionSlotWidgets.Add(NewSlot);

        }
    }

    for (int32 i = 0; i < Row; ++i)
    {
        for (int32 j = 0; j < Column; ++j)
        {
            UInventorySlotWidget* NewSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
            NewSlot->SetSizeBox(Width / Row, Height / Column);
            NewSlot->Index = i * Row + j;
            NewSlot->InventoryWidget = this;
            NewSlot->SetItem(DefaultSlot);

            ETCSlotWidgets.Add(NewSlot);

        }
    }

    
}

void UInventoryWidget::FillInventory(TArray<UInventorySlotWidget*> Slots)
{
    InventoryBoard->ClearChildren();
    SlotWidgets.Empty();

    int32 Row = 4;
    int32 Column = 4;
    UE_LOG(LogTemp, Warning, TEXT("Slot Size : %d"), EquipmentSlotWidgets.Num());


    for (int32 i = 0; i < Row; ++i)
    {
        for (int32 j = 0; j < Column; ++j)
        {
            int Index = i * Row + j;

        

            if (Index < EquipmentSlotWidgets.Num())
            {
                
                InventoryBoard->AddChildToUniformGrid(Slots[Index], i, j);
                //SlotWidgets.Add(Slots[Index]);
            }


                //SlotArray.Add(NewSlot);
            
        }
    }

    SlotWidgets = Slots;
}

void UInventoryWidget::SwapInventory(EINVENTORY_TYPE InventoryType)
{
    switch (InventoryState)
    {
    case 0:
        EquipmentSlotWidgets = SlotWidgets;
        break;
    case 1:
        ConsumptionSlotWidgets = SlotWidgets;
        break;
    case 2:
        ETCSlotWidgets = SlotWidgets;
        break;
    }

    switch (InventoryType)
    {
    case EINVENTORY_TYPE::EQUIPMENT:
        FillInventory(EquipmentSlotWidgets);
        InventoryState = 0;
        break;
    case EINVENTORY_TYPE::CONSUMPTION:
        FillInventory(ConsumptionSlotWidgets);
        InventoryState = 1;
        break;
    case EINVENTORY_TYPE::ETC:
        FillInventory(ETCSlotWidgets);
        InventoryState = 2;
        break;
    }
}

void UInventoryWidget::ClickEquipmentButton()
{
    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Click Button"));
    SwapInventory(EINVENTORY_TYPE::EQUIPMENT);
}

void UInventoryWidget::ClickConsumptionButton()
{
    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Click Button"));
    SwapInventory(EINVENTORY_TYPE::CONSUMPTION);
}

void UInventoryWidget::ClickEtcButton()
{
    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Click Button"));
    SwapInventory(EINVENTORY_TYPE::ETC);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "InventorySlotDrag.h"
#include "InventoryWidget.h"
#include "Components/TextBlock.h"
#include "Item.h"

void UInventorySlotWidget::AddItem(AItem* Item)
{
    if (Count == 0)
    {
        SlotTexture = Item->ItemTexture;
        SlotImage->SetBrushFromTexture(SlotTexture);
        SlotItem = Item;
    }
    
    Count++;
    UE_LOG(LogTemp, Warning, TEXT("%d"), Count);


    const FString CurrentCount = FString::Printf(TEXT("%d"), Count);
    SlotText->SetText(FText::FromString(CurrentCount));
}

void UInventorySlotWidget::SetItem(UInventorySlotWidget* OtherSlot)
{
    SlotTexture = OtherSlot->SlotTexture;
    SlotImage->SetBrushFromTexture(SlotTexture);

    SlotText->SetText(OtherSlot->SlotText->GetText());
    SlotItem = OtherSlot->SlotItem;
    Count = OtherSlot->Count;
}



void UInventorySlotWidget::SetSizeBox(float Width, float Height)
{
    SlotSizeBox->SetWidthOverride(Width);
    SlotSizeBox->SetHeightOverride(Height);
}

FReply UInventorySlotWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    FEventReply Reply;
    Reply.NativeReply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);


    if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton) == true)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Drag : Left Button Down"));

        Reply = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton);

    }

    return Reply.NativeReply;
}

FReply UInventorySlotWidget::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    FEventReply Reply;
    Reply.NativeReply = Super::NativeOnMouseButtonDoubleClick(InGeometry, InMouseEvent);

    if (Count > 0 && SlotItem != nullptr)
    {
        EINVENTORY_TYPE InventoryType = SlotItem->InventoryType;
        switch (InventoryType)
        {
        case EINVENTORY_TYPE::EQUIPMENT:
            EquippedItem(SlotItem);
            break;
        case EINVENTORY_TYPE::CONSUMPTION:
            UseItem(SlotItem->ItemType);
            break;
        }
    }


    return Reply.NativeReply;
}

void UInventorySlotWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& MouseEvent, UDragDropOperation*& OutOperation)
{
    Super::NativeOnDragDetected(InGeometry, MouseEvent, OutOperation);

    if (OutOperation == nullptr && this->SlotTexture != InventoryWidget->DefaultSlotTexture)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Drag : Drag Start"));

        UInventorySlotDrag* oper = NewObject<UInventorySlotDrag>();

        oper->SlotIndex = this->Index;

        oper->DefaultDragVisual = this;
        oper->Pivot = EDragPivot::MouseDown;
        OutOperation = oper;
    }
}

bool UInventorySlotWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
    Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

    UInventorySlotDrag* oper = Cast<UInventorySlotDrag>(InOperation);

    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Drag : Drag End"));

    if (oper != nullptr)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("Swap From : %d , To : %d"), oper->SlotIndex, this->Index));
        
        InventoryWidget->SwapSlot(oper->SlotIndex, this->Index);
       

    }

    return true;
}

void UInventorySlotWidget::UseItem(EITEM_TYPE ItemType)
{
    //int PrevCount = Count;

    switch (ItemType)
    {
    case EITEM_TYPE::MONEY:
    {
        this->SetItem(InventoryWidget->DefaultSlot);
        InventoryWidget->CurrentMoney += FMath::RandRange(100, 300);
        Count--;
        break;
    }
    }

    //Count = PrevCount;
    

    //GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Money : %d"), InventoryWidget->CurrentMoney));
    //const FString CurrentCount = FString::Printf(TEXT("%d"), Count);
    //SlotText->SetText(FText::FromString(CurrentCount));
}

void UInventorySlotWidget::EquippedItem(AItem* Item)
{
    // 장비창에 해당하는 장비타입 없으면 디폴트 위젯 , 있으면 위젯 교체 
    // 장착 먼저 
    AItem* NewItem = Item->EquippedItem();
    if (NewItem == nullptr)
    {
        this->SetItem(InventoryWidget->DefaultSlot);
    }
    else
    {
        //Count = 0;
        this->AddItem(NewItem);
    }


}

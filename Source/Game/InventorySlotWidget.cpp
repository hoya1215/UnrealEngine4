// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "InventorySlotDrag.h"
#include "InventoryWidget.h"
#include "Components/TextBlock.h"
#include "Item.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h" 
#include "Weapon.h"
#include "MyCharacter.h"
#include "MyGameInstance.h"

void UInventorySlotWidget::NativeConstruct()
{
    Super::NativeConstruct();

    GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

}

void UInventorySlotWidget::AddItem(FName Name)
{


    if (Count == 0)
    {
        auto ItemData = GameInstance->GetItemData(Name);
        UTexture2D* Texture = ItemData->ItemIcon.LoadSynchronous();
        SlotTexture = Texture;
        SlotImage->SetBrushFromTexture(SlotTexture);
        ItemName = Name;
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
    ItemName = OtherSlot->ItemName;
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

    if (ItemName != FName(TEXT("NULL")))
    {
        auto ItemData = GameInstance->GetItemData(ItemName);


        //EINVENTORY_TYPE InventoryType = CurrentItem->InventoryType;
        switch (ItemData->InventoryType)
        {
        case EINVENTORY_TYPE::EQUIPMENT:
            //EquippedItem(CurrentItem);
            EquippedItem(ItemName);
            break;
        case EINVENTORY_TYPE::CONSUMPTION:
            if (Count > 0)
            {
                auto Item = GetWorld()->SpawnActor<AItem>(ItemData->ItemClass);
                Item->UseItem();
                this->SetItem(InventoryWidget->DefaultSlot);
                Count--;
            }

            break;
        }
    }


    return Reply.NativeReply;
}

void UInventorySlotWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& MouseEvent, UDragDropOperation*& OutOperation)
{
    Super::NativeOnDragDetected(InGeometry, MouseEvent, OutOperation);

    if (OutOperation == nullptr && this->SlotTexture)
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

//void UInventorySlotWidget::UseItem(FName Name)
//{
//
//    switch (ItemType)
//    {
//    case EITEM_TYPE::MONEY:
//    {
//        this->SetItem(InventoryWidget->DefaultSlot);
//        InventoryWidget->CurrentMoney += FMath::RandRange(100, 300);
//        Count--;
//        break;
//    }
//    }
//}

void UInventorySlotWidget::EquippedItem(FName Name)
{
    // 장비창에 해당하는 장비타입 없으면 디폴트 위젯 , 있으면 위젯 교체 
    // 장착 먼저 
    AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

    auto ItemData = GameInstance->GetItemData(Name);

    MyCharacter->bCanPickUp = false;
    auto Item = GetWorld()->SpawnActor<AItem>(ItemData->ItemClass, FVector::ZeroVector, FRotator::ZeroRotator);
    if (Item)
    {
        FName PulledName = Item->EquippedItem();
        if (PulledName == FName(TEXT("NULL")))
        {
            this->SetItem(InventoryWidget->DefaultSlot);
        }
        else if (PulledName == FName(TEXT("Destroy")))
        {
            Item->Destroy();
        }
        else
        {
            //Count = 0;
            this->AddItem(PulledName);
        }


        if ((ItemData->EquipmentType == EEQUIPMENT_TYPE::MAIN ||
            ItemData->EquipmentType == EEQUIPMENT_TYPE::SUB ||
            ItemData->EquipmentType == EEQUIPMENT_TYPE::OTHER) && MyCharacter)
        {
            MyCharacter->ChangeSpeed();
            MyCharacter->WeaponChange.Broadcast();
        }
    }

    MyCharacter->bCanPickUp = true;

}

//void UInventorySlotWidget::EquippedItem(AItem* Item)
//{
//    // 장비창에 해당하는 장비타입 없으면 디폴트 위젯 , 있으면 위젯 교체 
//    // 장착 먼저 
//    // 아이템 소환 Item Name 으로 
//    AItem* NewItem = Item->EquippedItem();
//    if (NewItem == nullptr)
//    {
//        this->SetItem(InventoryWidget->DefaultSlot);
//    }
//    else
//    {
//        //Count = 0;
//        this->AddItem(NewItem);
//    }
//
//    AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
//    if (MyCharacter)
//    {
//        MyCharacter->ChangeSpeed();
//        MyCharacter->WeaponChange.Broadcast();
//    }
//}

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
#include "EquipmentWidget.h"
#include "EnhanceWidget.h"
#include "EnhanceSlotWidget.h"
#include "UIManager.h"
#include "ItemStatWidget.h"

void UInventorySlotWidget::NativeConstruct()
{
    Super::NativeConstruct();

    
    GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

    SlotData.ItemInfo.ItemName = FName("NULL");
    SlotData.ItemInfo.Level = 1;
    SlotData.Count = 0;
}


void UInventorySlotWidget::AddItem(FItemInfo ItemInfo)
{
    SlotData.ItemInfo = ItemInfo;

    FItemData* ItemData = GameInstance->GetItemData(ItemInfo.ItemName);

    if (SlotData.Count == 0)
    {
        

        
        if (ItemData)
        {
            UTexture2D* Texture = ItemData->ItemIcon.LoadSynchronous();
            SlotTexture = Texture;
            SlotImage->SetBrushFromTexture(SlotTexture);
        }


        if (CurrentSlot != nullptr)
        {
            CurrentSlot->SlotTexture = this->SlotTexture;
            CurrentSlot->SlotImage->SetBrushFromTexture(CurrentSlot->SlotTexture);
            CurrentSlot->SlotData.ItemInfo = ItemInfo;
            CurrentSlot->ItemStatWidget->FillStatText(ItemInfo);
        }

    }
    
    SlotData.Count++;

    FString Text;
    if (ItemData->InventoryType == EINVENTORY_TYPE::EQUIPMENT)
    {
        UpdateLevel();
    }
    else
    {
        Text = FString::Printf(TEXT("%d"), SlotData.Count);
        SlotText->SetText(FText::FromString(Text));
        if (CurrentSlot)
        {
            CurrentSlot->SlotText->SetText(FText::FromString(Text));
        }
    }


    ItemStatWidget->FillStatText(ItemInfo);

}

void UInventorySlotWidget::SetItem(UInventorySlotWidget* OtherSlot)
{
    SlotTexture = OtherSlot->SlotTexture;
    SlotImage->SetBrushFromTexture(SlotTexture);

    SlotText->SetText(OtherSlot->SlotText->GetText());
    SlotData = OtherSlot->SlotData;
    ItemStatWidget->FillStatText(SlotData.ItemInfo);

    if (CurrentSlot != nullptr)
    {
        CurrentSlot->SlotTexture = this->SlotTexture;
        CurrentSlot->SlotImage->SetBrushFromTexture(CurrentSlot->SlotTexture);
        CurrentSlot->SlotText->SetText(OtherSlot->SlotText->GetText());
        CurrentSlot->SlotData = OtherSlot->SlotData;
        CurrentSlot->ItemStatWidget->FillStatText(CurrentSlot->SlotData.ItemInfo);
    }

    
}

void UInventorySlotWidget::ShowItemStat()
{
    //// ������ �̸����� ���� �����ͼ� ���ͳ��� �����ְ� �ؽ�Ʈ ä���ֱ�
    //UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
    //auto BasicAbility = GameInstance->GetItemAbility(SlotData.ItemInfo.ItemName);
    //auto AbilityChange = GameInstance->GetItemAbilityChange(SlotData.ItemInfo.ItemName);

    //TArray<float> BasicStat = BasicAbility->GetStatList();
    //TArray<float> ChangeStat = AbilityChange->GetStatList();

    //for (int i = 0; i < BasicStat.Num(); ++i)
    //{
    //    BasicStat[i] += ChangeStat[i] * SlotData.ItemInfo.Level;
    //}

    //for (int i = 0; i < StatName.Num(); ++i)
    //{
    //    if (BasicStat[i] > 0.f)
    //    {

    //    }
    //}
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

    if (SlotData.ItemInfo.ItemName != FName(TEXT("NULL")))
    {
        AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
        auto ItemData = GameInstance->GetItemData(SlotData.ItemInfo.ItemName);

        if (UUIManager::Get()->GetEnhanceWidget()->GetVisibility() == ESlateVisibility::Visible)
        {
            if (ItemData->InventoryType == EINVENTORY_TYPE::EQUIPMENT)
            {
                UUIManager::Get()->GetEnhanceWidget()->ItemSlot->PushItem(this);
            }

        }
        else
        {
            


            //EINVENTORY_TYPE InventoryType = CurrentItem->InventoryType;
            switch (ItemData->InventoryType)
            {
            case EINVENTORY_TYPE::EQUIPMENT:
                //EquippedItem(CurrentItem);
                EquippedItem(SlotData);
                break;
            case EINVENTORY_TYPE::CONSUMPTION:
                if (InventoryWidget->ConsumptionSlotWidgets[this->Index]->SlotData.Count > 0)
                {
                    auto Item = GetWorld()->SpawnActor<AItem>(ItemData->ItemClass);
                    Item->UseItem();
                    InventoryWidget->ConsumptionSlotWidgets[this->Index]->SetItem(InventoryWidget->DefaultSlot);
                }

                break;
            }
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

void UInventorySlotWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

    if (SlotData.ItemInfo.ItemName != FName(TEXT("NULL")))
    {
        ItemStatWidget->SetVisibility(ESlateVisibility::Visible);
    }
}

void UInventorySlotWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseLeave(InMouseEvent);

    if (SlotData.ItemInfo.ItemName != FName(TEXT("NULL")))
    {
         ItemStatWidget->SetVisibility(ESlateVisibility::Hidden);
    }
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

void UInventorySlotWidget::EquippedItem(FSlotData Data)
{
    // ���â�� �ش��ϴ� ���Ÿ�� ������ ����Ʈ ���� , ������ ���� ��ü 
    // ���� ���� 
    AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

    auto ItemData = GameInstance->GetItemData(Data.ItemInfo.ItemName);

    MyCharacter->bCanPickUp = false;
    // ���� ���â�� �� ������ ��ü ������ ���Կ� �ϴ� �־��ְ� ���� ���Ⱑ ������ ��������
    auto Item = GetWorld()->SpawnActor<AItem>(ItemData->ItemClass, FVector::ZeroVector, FRotator::ZeroRotator);
    if (Item)
    {
        Item->SetItemInfo(SlotData.ItemInfo);

        UEquipmentSlotWidget* CurrentEquipmentSlot = UUIManager::Get()->GetEquipmentWidget()->EquipmentSlots[ItemData->EquipmentType];
        
        if (CurrentEquipmentSlot->SlotData.ItemInfo.ItemName == FName(TEXT("NULL")))
        {
            CurrentEquipmentSlot->PushEquipment(Data);
            InventoryWidget->EquipmentSlotWidgets[this->Index]->SetItem(InventoryWidget->DefaultSlot);

            if ((ItemData->EquipmentType == EEQUIPMENT_TYPE::MAIN ||
                ItemData->EquipmentType == EEQUIPMENT_TYPE::SUB ||
                ItemData->EquipmentType == EEQUIPMENT_TYPE::OTHER) && MyCharacter->GetMyWeapon() != nullptr)
            {
                Item->Destroy();
                return;
            }

            Item->EquippedItem(Data.ItemInfo);
            
        }
        else
        {
            FSlotData PulledData = CurrentEquipmentSlot->SlotData;
            CurrentEquipmentSlot->PushEquipment(Data);
            InventoryWidget->EquipmentSlotWidgets[this->Index]->SetItem(InventoryWidget->DefaultSlot);
            InventoryWidget->EquipmentSlotWidgets[this->Index]->AddItem(PulledData.ItemInfo);

            // ĳ���� ������ ������ ��� �ֱ� 
            switch (Item->EquipmentType)
            {
            case EEQUIPMENT_TYPE::WING:
                Item->UnEquippedItem();
                break;
            case EEQUIPMENT_TYPE::SHOES:
                Item->UnEquippedItem();
                break;
            case EEQUIPMENT_TYPE::HELMET:
                Item->UnEquippedItem();
                break;
            default:
                if (MyCharacter->GetMyWeapon() && (Item->EquipmentType == MyCharacter->GetMyWeapon()->EquipmentType))
                {
                    Item->UnEquippedItem();
                }
                break;
            }

            Item->EquippedItem(Data.ItemInfo);
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

void UInventorySlotWidget::UpdateLevel()
{
    FString Text = FString::Printf(TEXT("Lv.%d"), SlotData.ItemInfo.Level);
    SlotText->SetText(FText::FromString(Text));
    ItemStatWidget->FillStatText(SlotData.ItemInfo);
    if (CurrentSlot)
    {
        CurrentSlot->SlotText->SetText(FText::FromString(Text));
        CurrentSlot->ItemStatWidget->FillStatText(CurrentSlot->SlotData.ItemInfo);
    }

    
}

//void UInventorySlotWidget::EquippedItem(AItem* Item)
//{
//    // ���â�� �ش��ϴ� ���Ÿ�� ������ ����Ʈ ���� , ������ ���� ��ü 
//    // ���� ���� 
//    // ������ ��ȯ Item Name ���� 
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

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

    InventoryBoard->ClearChildren();
    CurrentSlotWidgets.Empty();

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

    GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

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


void UInventoryWidget::AddItemToInventory(FName Name)
{
    if (InventorySlotWidgetClass)
    {


        switch (GameInstance->GetItemData(Name)->InventoryType)
        {
        case EINVENTORY_TYPE::EQUIPMENT:
            if (CurrentSlotIndex_Equipment < MaxInventorySize)
            {
                for (int i = 0; i < EquipmentSlotWidgets.Num(); ++i)
                {
                    if (EquipmentSlotWidgets[i]->ItemName == FName("NULL"))
                    {
                        EquipmentSlotWidgets[i]->AddItem(Name);
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
                    if (ConsumptionSlotWidgets[i]->ItemName == Name)
                    {
                        ConsumptionSlotWidgets[i]->AddItem(Name);
                        bNew = false;
                        break;
                    }
                }

                if (bNew)
                {
                    for (int i = 0; i < ConsumptionSlotWidgets.Num(); ++i)
                    {
                        if (ConsumptionSlotWidgets[i]->ItemName == FName(TEXT("NULL")))
                        {
                            ConsumptionSlotWidgets[i]->AddItem(Name);
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
                    if (ETCSlotWidgets[i]->CurrentItem == nullptr)
                    {
                        ETCSlotWidgets[i]->AddItem(Name);
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
    Copy->SetItem(CurrentSlotWidgets[From]);


    CurrentSlotWidgets[From]->SetItem(CurrentSlotWidgets[To]);
    CurrentSlotWidgets[To]->SetItem(Copy);


}

void UInventoryWidget::CreateSlot()
{

    int32 Row = 4;
    int32 Column = 4;

    float Width = InventorySizeBox->WidthOverride;
    float Height = InventorySizeBox->HeightOverride;

    DefaultSlot = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
    DefaultSlot->SlotTexture = DefaultSlotTexture;
    DefaultSlot->ItemName = FName(TEXT("NULL"));

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
    CurrentSlotWidgets.Empty();

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
            } 
        }
    }

    CurrentSlotWidgets = Slots;
}

void UInventoryWidget::SwapInventory(EINVENTORY_TYPE InventoryType)
{
    switch (InventoryState)
    {
    case 0:
        EquipmentSlotWidgets = CurrentSlotWidgets;
        break;
    case 1:
        ConsumptionSlotWidgets = CurrentSlotWidgets;
        break;
    case 2:
        ETCSlotWidgets = CurrentSlotWidgets;
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

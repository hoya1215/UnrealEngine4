// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ItemStatWidget.h"
#include "Components/TextBlock.h"
#include "MyGameInstance.h"



void UItemStatWidget::NativeConstruct()
{
    Super::NativeConstruct();

    ResetStatText();

    SetVisibility(ESlateVisibility::Hidden);
}



void UItemStatWidget::FillStatText(FItemInfo ItemInfo)
{
    if (ItemInfo.ItemName == FName(TEXT("NULL")))
    {
        ResetStatText();
        return;
    }

    FString Name = FString::Printf(TEXT("%s"), *ItemInfo.ItemName.ToString());
    ItemName->SetText(FText::FromString(Name));


    // ������ �̸����� ���� �����ͼ� ���ͳ��� �����ְ� �ؽ�Ʈ ä���ֱ�
    UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
    auto ItemData = GameInstance->GetItemData(ItemInfo.ItemName);

    // ���� ������ �ɷ�ġ ���� ���
    if (ItemData->InventoryType == EINVENTORY_TYPE::EQUIPMENT)
    {
        auto BasicAbility = GameInstance->GetItemAbility(ItemInfo.ItemName);
        auto AbilityChange = GameInstance->GetItemAbilityChange(ItemInfo.ItemName);

        TArray<float> BasicStat = BasicAbility->GetStatList();
        TArray<float> ChangeStat = AbilityChange->GetStatList();

        for (int i = 0; i < BasicStat.Num(); ++i)
        {
            BasicStat[i] += ChangeStat[i] * ItemInfo.Level;
        }

        FString AllStatText;
        for (int i = 0; i < GameInstance->StatNameList.Num(); ++i)
        {
            if (BasicStat[i] != 0.f)
            {
                AllStatText += FString::Printf(TEXT("%s   %.1f \n"), *GameInstance->StatNameList[i].ToString(), BasicStat[i]);
            }
        }
        StatText->SetText(FText::FromString(AllStatText));
    }



}

void UItemStatWidget::ResetStatText()
{
    FString Default = FString::Printf(TEXT(""));
    ItemName->SetText(FText::FromString(Default));
    StatText->SetText(FText::FromString(Default));
    SetVisibility(ESlateVisibility::Hidden);
}

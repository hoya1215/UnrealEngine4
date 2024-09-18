// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Item.h"
#include "ItemStatWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class GAME_API UItemStatWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;


	void FillStatText(FItemInfo ItemInfo);
	void ResetStatText();
	
public:
	UPROPERTY(meta = (BindWidget))
		UTextBlock* ItemName;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* StatText;

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"  
#include "MyCharacterStatComponent.h"
#include "Weapon.h"
#include "SkillSlotWidget.h"
#include "Skill_Tag.h"
#include "AcquireWidget.h"
#include "MyGameInstance.h"
#include "Util.h"



UMyHUD::UMyHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UAcquireWidget> AW(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_Acquire.WBP_Acquire_C'"));
	if (AW.Succeeded())
	{
		AcquireWidgetClass = AW.Class;
	}
}

void UMyHUD::NativeConstruct()
{
	Super::NativeConstruct();

	MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));



	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/Circle.Circle'"));
	DefaultTexture = Texture;

	CurrentWeapon->SetBrushFromTexture(DefaultTexture);

	

	if (AcquireWidgetClass)
	{
		// 위젯 세개 만들기
		for (int i = 0; i < MaxAcquireWidgetCount; ++i)
		{
			UAcquireWidget* AcquireWidget = CreateWidget<UAcquireWidget>(GetWorld(), AcquireWidgetClass);
			AcquireWidget->AddToViewport();
			AcquireWidgetUp.AddUObject(AcquireWidget, &UAcquireWidget::Up);
			AcquireWidget->SetVisibility(ESlateVisibility::Hidden);
			AcquireWidgets.Enqueue(AcquireWidget);
		}
	}

	AcquireWidgetTop->SetVisibility(ESlateVisibility::Hidden);
	AcquireWidgetMiddle->SetVisibility(ESlateVisibility::Hidden);
	AcquireWidgetBottom->SetVisibility(ESlateVisibility::Hidden);


	//CurrentWeapon->SetVisibility(ESlateVisibility::Hidden);
}



void UMyHUD::UpdateHp()
{

	FString CurrentHp = FString::Printf(TEXT("Hp : %.1f"), MyCharacter->Stat->GetHp());
	HpText->SetText(FText::FromString(CurrentHp));

	float HpRatio = (float)MyCharacter->Stat->GetHp() / (float)MyCharacter->Stat->GetMaxHp();
	Hp_Bar->SetPercent(HpRatio);
}

void UMyHUD::UpdateExp(float ExpRatio)
{
	FString CurrentExp = FString::Printf(TEXT("Exp : %.1f %"), ExpRatio * 100.f);
	ExpText->SetText(FText::FromString(CurrentExp));

	Exp_Bar->SetPercent(ExpRatio);
}

void UMyHUD::UpdateLevel(int Level)
{
	FString CurrentLevel = FString::Printf(TEXT("Lv %d"), Level);
	LevelText->SetText(FText::FromString(CurrentLevel));
}

void UMyHUD::UpdateWeaponImage()
{
	//CurrentWeapon->SetBrushFromTexture(MyCharacter->GetMyWeapon()->ItemTexture);
	if (MyCharacter->GetMyWeapon() != nullptr)
	{
		CurrentWeapon->SetBrushFromMaterial(MyCharacter->GetMyWeapon()->MaterialTexture);
	}
	else
		CurrentWeapon->SetBrushFromTexture(DefaultTexture);
}

void UMyHUD::AcquireItem(FName ItemName)
{
	// 아이템 텍스처 설정 , broadcast , 실행 , 맨위로 올려주기
	UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetGameInstance());
	auto ItemData = GameInstance->GetItemData(ItemName);

	SwapAcquireWidget();
	AcquireWidgetBottom->AcquireItem(ItemData->ItemIcon.LoadSynchronous(), true, 0.01f);

	// TODO broadcast
	//AcquireWidgetUp.Broadcast();


	// Use Queue
	//UAcquireWidget* CurrentAcquireWidget = nullptr;
	//AcquireWidgets.Dequeue(CurrentAcquireWidget);
	//CurrentAcquireWidget->AcquireItem(ItemData->ItemIcon.LoadSynchronous());
	//AcquireWidgets.Enqueue(CurrentAcquireWidget);
}

void UMyHUD::SwapAcquireWidget()
{
	if (AcquireWidgetMiddle->Texture != nullptr)
	{
		AcquireWidgetTop->AcquireItem(AcquireWidgetMiddle->Texture, false, AcquireWidgetMiddle->DisappearTime);
	}

	if (AcquireWidgetBottom->Texture != nullptr)
	{
		AcquireWidgetMiddle->AcquireItem(AcquireWidgetBottom->Texture, false, AcquireWidgetBottom->DisappearTime);
	}
}

void UMyHUD::SetCharacter(AMyCharacter* CurrentCharacter)
{
	MyCharacter = CurrentCharacter;

	MyCharacter->HpChange.AddUObject(this, &UMyHUD::UpdateHp);
	MyCharacter->WeaponChange.AddUObject(this, &UMyHUD::UpdateWeaponImage);

	FString Hp = FString::Printf(TEXT("Hp : %d"), MyCharacter->Stat->GetMaxHp());

	HpText->SetText(FText::FromString(Hp));

	//CurrentWeapon->SetBrushFromTexture(MyCharacter->GetMyWeapon()->ItemTexture);

	//MyCharacter->HpChange.AddUObject(this, &UMyHUD::UpdateHp);
	//MyCharacter->WeaponChange.AddUObject(this, &UMyHUD::UpdateWeaponImage);
	TabSkill->SetProgressBarImage(MyCharacter->TagSkill->SkillTexture);
}
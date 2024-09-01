// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"  
#include "MyCharacterStatComponent.h"
#include "Weapon.h"


void UMyHUD::NativeConstruct()
{
	Super::NativeConstruct();

	MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (MyCharacter)
	{

		FString Hp = FString::Printf(TEXT("Hp : %d"), MyCharacter->Stat->GetMaxHp());

		HpText->SetText(FText::FromString(Hp));

		//CurrentWeapon->SetBrushFromTexture(MyCharacter->GetMyWeapon()->ItemTexture);

		MyCharacter->HpChange.AddUObject(this, &UMyHUD::UpdateHp);
		MyCharacter->WeaponChange.AddUObject(this, &UMyHUD::UpdateWeaponImage);
	}


	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/Circle.Circle'"));
	DefaultTexture = Texture;

	CurrentWeapon->SetBrushFromTexture(DefaultTexture);

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

void UMyHUD::SetCharacter(AMyCharacter* CurrentCharacter)
{
	MyCharacter = CurrentCharacter;

	MyCharacter->HpChange.AddUObject(this, &UMyHUD::UpdateHp);
	MyCharacter->WeaponChange.AddUObject(this, &UMyHUD::UpdateWeaponImage);
}
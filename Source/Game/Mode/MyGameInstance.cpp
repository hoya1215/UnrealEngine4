// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Sound/SoundManager.h"

UMyGameInstance::UMyGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> CharacterData(TEXT("DataTable'/Game/Custom/Data/DT_Character.DT_Character'"));
	if (CharacterData.Succeeded())
		MyStats = CharacterData.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> WD(TEXT("DataTable'/Game/Custom/Data/DT_Weapon.DT_Weapon'"));
	if (WD.Succeeded())
		WeaponData = WD.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> ED(TEXT("DataTable'/Game/Custom/Data/DT_Enemy.DT_Enemy'"));
	if (ED.Succeeded())
		EnemyData = ED.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> ID(TEXT("DataTable'/Game/Custom/Data/DT_Item.DT_Item'"));
	if (ID.Succeeded())
		ItemData = ID.Object;


}

void UMyGameInstance::Init()
{
	Super::Init();

	SoundManager = NewObject<USoundManager>();
}

FCharacterData* UMyGameInstance::GetStatData(int32 level)
{
	// 데이터 찾아오기 



	return 	MyStats->FindRow<FCharacterData>(*FString::FromInt(level), TEXT(""));;
}

FWeaponData* UMyGameInstance::GetWeaponData(FName Name)
{
	return WeaponData->FindRow<FWeaponData>(Name, TEXT(""));
}

FEnemyData* UMyGameInstance::GetEnemyData(FName Name)
{
	return EnemyData->FindRow<FEnemyData>(Name, TEXT(""));
}

FItemData* UMyGameInstance::GetItemData(FName Name)
{
	return ItemData->FindRow<FItemData>(Name, TEXT(""));
}
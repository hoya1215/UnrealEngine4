// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundManager.h"
#include "ItemPool.h"
#include "PoolStorage.h"

UMyGameInstance::UMyGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> CharacterData(TEXT("DataTable'/Game/Custom/Data/DT_Character.DT_Character'"));
	if (CharacterData.Succeeded())
		MyStats = CharacterData.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> WD(TEXT("DataTable'/Game/Custom/Data/DT_Weapon.DT_Weapon'"));
	if (WD.Succeeded())
		WeaponData = WD.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> PD(TEXT("DataTable'/Game/Custom/Data/DT_Pet.DT_Pet'"));
	if (PD.Succeeded())
		PetData = PD.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> ED(TEXT("DataTable'/Game/Custom/Data/DT_Enemy.DT_Enemy'"));
	if (ED.Succeeded())
		EnemyData = ED.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> ID(TEXT("DataTable'/Game/Custom/Data/DT_Item.DT_Item'"));
	if (ID.Succeeded())
		ItemData = ID.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> CD(TEXT("DataTable'/Game/Custom/Data/DT_Clothes.DT_Clothes'"));
	if (CD.Succeeded())
		ClothesData = CD.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> IA(TEXT("DataTable'/Game/Custom/Data/DT_ItemAbility.DT_ItemAbility'"));
	if (IA.Succeeded())
		ItemAbility = IA.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> IAC(TEXT("DataTable'/Game/Custom/Data/DT_AbilityChange.DT_AbilityChange'"));
	if (IAC.Succeeded())
		ItemAbilityChange = IAC.Object;
}

void UMyGameInstance::Init()
{
	Super::Init();

	SoundManager = NewObject<USoundManager>();

	TArray<AActor*> PoolStorages;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APoolStorage::StaticClass(), PoolStorages);

	for (auto Pool : PoolStorages)
	{
		PoolStorage = Cast<APoolStorage>(Pool);
		break;
	}

	if (!PoolStorage)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Pool Storage"));
	}

	StatNameList.Add(FName(TEXT("Power")));
	StatNameList.Add(FName(TEXT("Speed")));
	StatNameList.Add(FName(TEXT("Defense")));
	StatNameList.Add(FName(TEXT("Hp")));


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

FPetData* UMyGameInstance::GetPetData(FName Name)
{
	return PetData->FindRow<FPetData>(Name, TEXT(""));
}

FClothesData* UMyGameInstance::GetClothesData(FName Name)
{
	return ClothesData->FindRow<FClothesData>(Name, TEXT(""));
}

FEnemyData* UMyGameInstance::GetEnemyData(FName Name)
{
	return EnemyData->FindRow<FEnemyData>(Name, TEXT(""));
}

FItemData* UMyGameInstance::GetItemData(FName Name)
{
	return ItemData->FindRow<FItemData>(Name, TEXT(""));
}

FAbility* UMyGameInstance::GetItemAbility(FName Name)
{
	return ItemAbility->FindRow<FAbility>(Name, TEXT(""));
}

FAbility* UMyGameInstance::GetItemAbilityChange(FName Name)
{
	return ItemAbilityChange->FindRow<FAbility>(Name, TEXT(""));
}

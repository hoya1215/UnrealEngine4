// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> CharacterData(TEXT("DataTable'/Game/Custom/Data/DT_Character.DT_Character'"));
	if (CharacterData.Succeeded())
		MyStats = CharacterData.Object;
}

FCharacterData* UMyGameInstance::GetStatData(int32 level)
{
	// ������ ã�ƿ��� 



	return 	MyStats->FindRow<FCharacterData>(*FString::FromInt(level), TEXT(""));;
}

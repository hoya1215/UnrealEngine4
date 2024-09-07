// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Skill_Tag.generated.h"

class AMyCharacter;
class ACharacter_Tag;
class UWorld;
/**
 * 
 */
UCLASS()
class GAME_API USkill_Tag : public UObject
{
	GENERATED_BODY()
public:
	USkill_Tag();

	void BeginPlay(UWorld* World, AMyCharacter* Character);

	void Play();

public:
	UPROPERTY()
		TSubclassOf<ACharacter_Tag> TagCharacterClass;

	UPROPERTY()
		ACharacter_Tag* TagCharacter;

	UPROPERTY()
		AMyCharacter* MyCharacter;
};

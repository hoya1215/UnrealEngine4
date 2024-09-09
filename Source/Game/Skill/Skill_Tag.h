// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "Skill_Tag.generated.h"

class AMyCharacter;
class ACharacter_Tag;
class UWorld;
class UTexture2D;
/**
 * 
 */
UCLASS()
class GAME_API USkill_Tag : public USkill
{
	GENERATED_BODY()
public:
	USkill_Tag();

	virtual void BeginPlay(UWorld* World, AMyCharacter* Character) override;

	virtual void Play() override;

public:
	UPROPERTY()
		TSubclassOf<ACharacter_Tag> TagCharacterClass;

	UPROPERTY()
		ACharacter_Tag* TagCharacter;





};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Skill.generated.h"

class AMyCharacter;
/**
 * 
 */
UCLASS()
class GAME_API USkill : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay(UWorld* World, AMyCharacter* Character);

	virtual void Play();

public:
	UPROPERTY()
		AMyCharacter* MyCharacter;

	UPROPERTY()
		UTexture2D* SkillTexture;

	float CoolTime = 0.f;
};

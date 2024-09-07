// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkillManager.generated.h"

class USkill_Tag;
/**
 * 
 */
UCLASS()
class GAME_API USkillManager : public UObject
{
	GENERATED_BODY()
	
public:
	USkillManager();

public:
	UPROPERTY()
		USkill_Tag* Skill_Tag;
};

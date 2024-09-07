// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill/SkillManager.h"
#include "Skill_Tag.h"

USkillManager::USkillManager()
{
	Skill_Tag = NewObject<USkill_Tag>();

}
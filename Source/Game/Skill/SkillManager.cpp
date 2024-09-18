// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill/SkillManager.h"
#include "Skill_Tag.h"
#include "Util.h"
#include "SkillSlotWidget.h"
#include "UIManager.h"
#include "MyHUD.h"

USkillManager* USkillManager::SkillManager = nullptr;

USkillManager::USkillManager()
{
	Skill_Tag = NewObject<USkill_Tag>();
}

USkillManager* USkillManager::Get()
{
	if (SkillManager == nullptr)
	{
		SkillManager = NewObject<USkillManager>();
		SkillManager->AddToRoot();
	}

	return SkillManager;
}

void USkillManager::BeginPlay(UWorld* World, AMyCharacter* MyCharacter)
{
	Skill_Tag->BeginPlay(World, MyCharacter);
	auto HUD = UUIManager::Get()->GetHUD();
	HUD->TabSkill->SetSkill(Skill_Tag);
}
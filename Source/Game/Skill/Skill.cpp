// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill/Skill.h"
#include "MyCharacter.h"
#include "Character_Tag.h"

void USkill::BeginPlay(UWorld* World, AMyCharacter* Character)
{
	if (World)
	{
		MyCharacter = Character;
	}

}

void USkill::Play()
{

}
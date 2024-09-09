// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill/Skill_Tag.h"
#include "Character_Tag.h"
#include "MyCharacter.h"
#include "Util.h"
#include "TagAnimInstance.h"

USkill_Tag::USkill_Tag()
{
	ConstructorHelpers::FClassFinder<ACharacter_Tag> CT(TEXT("Blueprint'/Game/Custom/Blueprint/BP_Character_Tag.BP_Character_Tag_C'"));
	if (CT.Succeeded())
	{
		TagCharacterClass = CT.Class;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> ST(TEXT("Texture2D'/Game/Custom/Resources/Tag.Tag'"));
	if (ST.Succeeded())
	{
		SkillTexture = ST.Object;
	}

	CoolTime = 5.f;
}

void USkill_Tag::BeginPlay(UWorld* World, AMyCharacter* Character)
{
	USkill::BeginPlay(World, Character);

	if (World)
	{
		TagCharacter = World->SpawnActor<ACharacter_Tag>(TagCharacterClass, FVector::ZeroVector, FRotator::ZeroRotator);
		TagCharacter->SetActorHiddenInGame(true);
	}

}

void USkill_Tag::Play()
{
	UTagAnimInstance* AnimInstance = Cast<UTagAnimInstance>(TagCharacter->GetMesh()->GetAnimInstance());

	if (!AnimInstance->Montage_IsPlaying(AnimInstance->AttackMontage))
	{
		TagCharacter->SetActorLocation(MyCharacter->GetActorLocation() + MyCharacter->GetActorForwardVector() * 100);
		TagCharacter->SetActorRotation(MyCharacter->GetActorRotation());
		TagCharacter->SetActorHiddenInGame(false);
		TagCharacter->SetActorTickEnabled(true);


		AnimInstance->PlayAttackMontage();
	}


	
}
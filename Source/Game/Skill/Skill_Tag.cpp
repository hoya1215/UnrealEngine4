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

	

}

void USkill_Tag::BeginPlay(UWorld* World, AMyCharacter* Character)
{
	if (World)
	{
		TagCharacter = World->SpawnActor<ACharacter_Tag>(TagCharacterClass, FVector::ZeroVector, FRotator::ZeroRotator);
		TagCharacter->SetActorHiddenInGame(true);
		MyCharacter = Character;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No World"));
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
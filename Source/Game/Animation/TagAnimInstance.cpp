// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/TagAnimInstance.h"
#include "Character_Tag.h"
#include "Particles/ParticleSystemComponent.h"

UTagAnimInstance::UTagAnimInstance()
{
	ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Custom/Animation/TagMontage.TagMontage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

void UTagAnimInstance::NativeInitializeAnimation()
{
	auto Pawn = TryGetPawnOwner();
	TagCharacter = Cast<ACharacter_Tag>(Pawn);
}

void UTagAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (bMove)
	{
		FVector NewLocation = TagCharacter->GetActorLocation();
		NewLocation += TagCharacter->GetActorForwardVector() * 4.f;

		TagCharacter->SetActorLocation(NewLocation);
	}
}

void UTagAnimInstance::PlayAttackMontage()
{
	if (!Montage_IsPlaying(AttackMontage))
	{
		Montage_Play(AttackMontage, 1.f);
	}
}

void UTagAnimInstance::AnimNotify_AttackEnd()
{

	TagCharacter->EffectComponent->Deactivate();
	TagCharacter->SetActorLocation(FVector::ZeroVector);
	TagCharacter->SetActorHiddenInGame(false);
	TagCharacter->SetActorTickEnabled(true);
}

void UTagAnimInstance::AnimNotify_MoveStart()
{


	bMove = true;
}

void UTagAnimInstance::AnimNotify_MoveEnd()
{
	bMove = false;
}

void UTagAnimInstance::AnimNotify_Attack()
{
	TagCharacter->Attack();
}

void UTagAnimInstance::AnimNotify_Effect()
{
	TagCharacter->EffectComponent->Activate();
}

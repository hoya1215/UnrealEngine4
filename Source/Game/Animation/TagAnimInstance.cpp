// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/TagAnimInstance.h"
#include "Character_Tag.h"
#include "DrawDebugHelpers.h"
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
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, TagCharacter);

	float Range = 200.0f;
	float Radius = 50.f;

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT HitResult,
		TagCharacter->GetActorLocation(),
		TagCharacter->GetActorLocation() + TagCharacter->GetActorForwardVector() * Range,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel3,
		FCollisionShape::MakeSphere(Radius),
		Params
	);

	// 디버거용 그림
	FVector Vec = TagCharacter->GetActorForwardVector() * Range;
	FVector Center = TagCharacter->GetActorLocation() + Vec * 0.5f;
	float HalfHeight = Range * 0.5f + Radius;
	FQuat Rotation = FRotationMatrix::MakeFromZ(Vec).ToQuat();
	FColor DrawColor;
	if (bResult)
		DrawColor = FColor::Green;
	else
		DrawColor = FColor::Red;

	DrawDebugCapsule(GetWorld(), Center, HalfHeight, Radius, Rotation, DrawColor, false, 2.f);

	if (bResult && HitResult.Actor.IsValid())
	{

		FDamageEvent event;
		HitResult.Actor->TakeDamage(TagCharacter->Power, event, TagCharacter->GetController(), TagCharacter);
	}
}

void UTagAnimInstance::AnimNotify_Effect()
{
	TagCharacter->EffectComponent->Activate();
}

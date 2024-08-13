// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyCharacter.h"
#include "GameFramework/Character.h"
#include "MyCharacterStatComponent.h"

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<AMyCharacter>(Pawn);
		if (Character)
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();
			IsWalking = Character->IsWalking;
			IsFlying = Character->bIsFlying;
			Hp = Character->Stat->GetHp();
		}
	}
}
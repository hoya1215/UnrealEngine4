// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyCharacter.h"
#include "GameFramework/Character.h"
#include "MyCharacterStatComponent.h"

void UMyAnimInstance::NativeInitializeAnimation()
{
	auto Pawn = TryGetPawnOwner();
	MyCharacter = Cast<AMyCharacter>(Pawn);
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (MyCharacter)
	{
		Speed = MyCharacter->GetVelocity().Size();

		IsFalling = MyCharacter->GetMovementComponent()->IsFalling();
		IsWalking = MyCharacter->bIsWalking;
		IsFlying = MyCharacter->bIsFlying;
		Hp = MyCharacter->Stat->GetHp();
		CurrentWeaponState = MyCharacter->CurrentWeaponState;
		IsWeaponSwapping = MyCharacter->bIsWeaponSwapping;
		IsAttacking = MyCharacter->bIsAttacking;
		ForwardValue = MyCharacter->ForwardValue;
		SideValue = MyCharacter->SideValue;
	}
}

void UMyAnimInstance::AnimNotify_SwapEnd()
{
	if (MyCharacter)
	{
		MyCharacter->bIsWeaponSwapping = false;
		switch (MyCharacter->CurrentWeaponState)
		{
		case 0:
			MyCharacter->ChangeCurrentWeapon(EEQUIPMENT_TYPE::MAIN);
			break;
		case 1:
			MyCharacter->ChangeCurrentWeapon(EEQUIPMENT_TYPE::SUB);
			break;
		case 2:
			MyCharacter->ChangeCurrentWeapon(EEQUIPMENT_TYPE::OTHER);
			break;
		}
	}
}

void UMyAnimInstance::AnimNotify_SwordAttack()
{

	if (MyCharacter)
	{
		MyCharacter->OtherAttack();
	}
}
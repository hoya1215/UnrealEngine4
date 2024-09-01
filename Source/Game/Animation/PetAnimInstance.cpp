// Fill out your copyright notice in the Description page of Project Settings.


#include "PetAnimInstance.h"
#include "Pet.h"

void UPetAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	auto Pawn = TryGetPawnOwner();
	MyPet = Cast<APet>(Pawn);
}

void UPetAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	//auto Pawn = TryGetPawnOwner();
	if (MyPet)
	{


		//auto Pet = Cast<APet>(Pawn);
		if (MyPet)
		{
			bIsAttacking = MyPet->bIsAttacking;
		}
	}
}

void UPetAnimInstance::AnimNotify_Attack()
{
	if (MyPet)
	{
		MyPet->Attack();
	}
}

void UPetAnimInstance::AnimNotify_AttackEnd()
{
	AttackEnd.Broadcast();
	if (MyPet)
	{
		MyPet->bIsAttacking = false;
		bIsAttacking = false;
	}
}
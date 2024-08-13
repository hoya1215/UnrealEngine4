// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PetAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FAttackEnd)
/**
 * 
 */
UCLASS()
class GAME_API UPetAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION()
		void AnimNotify_Attack();

	UFUNCTION()
		void AnimNotify_AttackEnd();

	FAttackEnd AttackEnd;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		bool bIsAttacking;

private:
	UPROPERTY()
		class APet* MyPet;
	
};

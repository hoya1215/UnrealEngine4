// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

class AMyCharacter;

/**
 * 
 */
UCLASS()
class GAME_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION()
		void AnimNotify_SwapEnd();

	UFUNCTION()
		void AnimNotify_SwordAttack();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		bool IsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		bool IsWalking;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		bool IsFlying;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		bool IsWeaponSwapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		bool IsAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	int CurrentWeaponState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		int32 Hp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		int ForwardValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		int SideValue;


private:
	UPROPERTY()
		AMyCharacter* MyCharacter;
};

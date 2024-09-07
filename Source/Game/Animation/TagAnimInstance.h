// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TagAnimInstance.generated.h"

class ACharacter_Tag;
/**
 * 
 */
UCLASS()
class GAME_API UTagAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UTagAnimInstance();

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void PlayAttackMontage();

	UFUNCTION()
	void AnimNotify_AttackEnd();

	UFUNCTION()
		void AnimNotify_MoveStart();

	UFUNCTION()
		void AnimNotify_MoveEnd();

	UFUNCTION()
		void AnimNotify_Attack();

	UFUNCTION()
		void AnimNotify_Effect();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bIsAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UAnimMontage* AttackMontage;

private:


	UPROPERTY()
		ACharacter_Tag* TagCharacter;

	bool bMove = false;
};

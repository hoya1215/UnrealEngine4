// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyGameModeBase.h"
#include "MyEnemy.generated.h"

UCLASS()
class GAME_API AMyEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	AMyEnemy();

	// Çàµ¿
	void Attack();


	virtual void Die();
	// Get Set
	int32 GetEnemyTypeIndex(EENEMY_TYPE EEnemyType);


protected:
	virtual void BeginPlay() override;


public:
	virtual void Tick(float DeltaTime) override;


	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public:


	// Util
	UPROPERTY()
		float RotateRate = 180.f; // Sensitivity

	UPROPERTY()
		bool IsZoom = false;

	UPROPERTY(VisibleAnywhere)
		class UMyCharacterStatComponent* Stat;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsWalking = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsAttack = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsPicking = false;

	FTimerHandle DieTimer;
	float DieTime = 3.f;

	UPROPERTY()
		EENEMY_TYPE EnemyType;

	float FireGunDamageTime = 60.f;

private:
	UPROPERTY()
		class UEnemyAnimInstance* EnemyAnimInstance;


};

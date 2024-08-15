// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AWeapon : public AItem
{
	GENERATED_BODY()
	
public:
	AWeapon();
	
	virtual AItem* EquippedItem() override;

public:


	UPROPERTY(VisibleAnywhere)
		class UParticleSystem* Effect;

	UPROPERTY()
		int MaxBulletCount;

	UPROPERTY()
		int CurrentBulletCount;

	UPROPERTY()
		int WeaponState;
};

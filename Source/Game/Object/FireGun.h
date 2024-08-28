// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "FireGun.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AFireGun : public AWeapon
{
	GENERATED_BODY()

public:
	AFireGun();

	virtual void BeginPlay() override;
};

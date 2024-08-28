// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Sword.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API ASword : public AWeapon
{
	GENERATED_BODY()

public:
	ASword();


protected:
	virtual void BeginPlay() override;

public:

};

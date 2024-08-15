// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.h"
#include "Gun.generated.h"

DECLARE_MULTICAST_DELEGATE(FPickUp)
UCLASS()
class GAME_API AGun : public AWeapon
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();


public:
	FPickUp PickUp;

	UPROPERTY()
		class UStaticMeshComponent* MyGun;

	bool bContainInventory = false;

};

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

	FPickUp PickUp;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;


private:
	// weapon 으로 옮겨주기?
	virtual void OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//int GetBulletCount() { return BulletCount; }

public:
	UPROPERTY()
		class UStaticMeshComponent* MyGun;

	//UPROPERTY(VisibleAnywhere)
	//	class UBoxComponent* Trigger;

	//UPROPERTY(VisibleAnywhere)
	//	class UParticleSystem* GunEffect;


	bool bContainInventory = false;

};

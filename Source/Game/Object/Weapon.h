// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "MyGameInstance.h"
#include "Weapon.generated.h"

class USoundCue;

USTRUCT()
struct FWeaponInfo
{
	GENERATED_BODY()

	UPROPERTY()
		int Power;

	UPROPERTY()
		int Speed;
};


/**
 * 
 */
UCLASS()
class GAME_API AWeapon : public AItem
{
	GENERATED_BODY()
	
public:
	AWeapon();

	virtual void UnEquippedItem() override;

	virtual	void OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	virtual void EquippedItem(FItemInfo Info) override;
	virtual void AttachToCharacter() override;
	//virtual AItem* EquippedItem() override;

	FWeaponInfo GetWeaponInfo() { return WeaponInfo; }
	void SetWeaponInfo(FName Name);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UParticleSystemComponent* EffectComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UParticleSystem* Effect;

	UPROPERTY()
		int MaxBulletCount;

	UPROPERTY()
		int CurrentBulletCount;

	UPROPERTY()
		int WeaponState;

	UPROPERTY()
		FWeaponInfo WeaponInfo;

	UPROPERTY()
	class UMaterialInterface* MaterialTexture;

	UPROPERTY()
		USoundCue* AttackSound;
};

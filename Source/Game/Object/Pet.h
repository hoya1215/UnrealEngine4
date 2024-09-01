// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.h"
#include "GameFramework/Character.h"
#include "Pet.generated.h"

class AItem;

USTRUCT()
struct FPetInfo
{
	GENERATED_BODY()

		UPROPERTY()
		bool bCanAttack;

	UPROPERTY()
		bool bCanMagnet;

	UPROPERTY()
		int Power;

	UPROPERTY()
		float AttackRange;

	UPROPERTY()
		float MagnetRange;

	UPROPERTY()
		float AttackSpeed;
};

UCLASS()
class GAME_API APet : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Attack();
	void SearchEnemy();
	void SearchItem();
	void MagnetItem(AItem* Item);
	void Stop();
	void ReStart();

	FRotator GetDefaultRotation() { return DefaultRotation; }
	void SetDefaultRotation(FRotator NewRotation) { DefaultRotation = NewRotation; }
	void SetPetInfo(FName Name);
	void AttackEffectBegin();
	void AttackEffectEnd();

public:
	UPROPERTY()
		FName PetName;

	UPROPERTY()
		FPetInfo PetInfo;

	// 자석 효과
	UPROPERTY()
		bool bIsMagnet = true; 

	UPROPERTY()
		float MagnetArrange = 800.f;

	// 공격 효과
	UPROPERTY()
		bool bCanAttack = false;

	UPROPERTY()
		bool bIsAttacking = false;

	UPROPERTY()
		class UParticleSystem* AttackEffect;

	UPROPERTY()
		class UParticleSystemComponent* AttackEffectComponent;
	// 공격 범위
	UPROPERTY()
		float AttackArrange;

	UPROPERTY()
		int Power = 10;

	UPROPERTY()
		FVector EnemyLocation;

	UPROPERTY()
		class AMyEnemy* EnemyTarget;


private:
	UPROPERTY(EditAnywhere, Category = "Mesh")
		class USkeletalMeshComponent* SkeletalMesh;

	FRotator DefaultRotation;

	FTimerHandle EffectTimer;


	 
};

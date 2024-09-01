// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyCharacterStatComponent.generated.h"

class AMyCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_API UMyCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:	
	void UpdateExp(float NewExp);
	void LevelUp(int Value);

	void SetLevel(int32 CurrentLevel);
	void SetHp(float NewHp);
	void SetPower(int32 NewPower);
	void SetDefense(int32 NewDefense);
	void OnAttacked(float DamageAmount);
	void UpdateEnhancePoint(int Point)
	{
		EnhancePoint += Point;
	}

	int32 GetLevel() { return Level; }
	int32 GetMaxLevel() { return MaxLevel; }
	float GetHp() { return Hp; }
	int32 GetPower() { return Power; }
	int32 GetDefense() { return Defense; }
	float GetMaxHp();
	int GetEnhancePoint() { return EnhancePoint; }
	float GetCurrentExp() { return CurrentExp; }

	int32 GetPowerIncludeLevel(int32 CharacterLevel, int32 EnemyLevel, int32 CurrentPower);
	int32 GetDamageIncludeDefense(int32 EnemyPower, int32 CurrentDefense);

public:
	float MaxDefense = 100.f;
	int MaxLevelDifference = 10;

	AMyCharacter* MyCharacter;

private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 Level;

	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	float Hp;

	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 Power;

	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
		int32 Defense;

	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
		int32 EnhancePoint = 5;

	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
		float CurrentExp = 0.f;

	int32 MaxLevel = 10;
};

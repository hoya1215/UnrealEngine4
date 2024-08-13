// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyEnemy.h"
#include "Enemy_Small.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AEnemy_Small : public AMyEnemy
{
	GENERATED_BODY()
	
public:
	AEnemy_Small();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//virtual void Die() override;

	void StartAppear();
	void EndAppear();

public:
	FVector StartLocation;
	FVector EndLocation;
	float AppearTime = 2.f;
	float CurrentAppearTime = 0.f;
	bool bIsAppear =false;


};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyEnemy.h"
#include "Enemy_Boss.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AEnemy_Boss : public AMyEnemy
{
	GENERATED_BODY()
	
public:
	AEnemy_Boss();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	

public:
	UPROPERTY()
		class ARock* MyRock;

};

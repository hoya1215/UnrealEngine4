// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/Item.h"
#include "MyCharacter.h"
#include "MyCharacterStatComponent.h"
#include "Potion.generated.h"

class PotionFunction
{
public:
	static void RecoverHp(AMyCharacter* MyCharacter, float Value)
	{
		float NewHp = MyCharacter->Stat->GetHp();
		NewHp = FMath::Max(MyCharacter->Stat->GetMaxHp(), NewHp + Value);
		MyCharacter->Stat->SetHp(NewHp);
		MyCharacter->HpChange.Broadcast();
	}
};

/**
 * 
 */
UCLASS()
class GAME_API APotion : public AItem
{
	GENERATED_BODY()
	
public:
	APotion();

	virtual void UseItem() override;

	virtual void BeginPlay() override;
public:
	UPROPERTY()
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY()
		float Value;
};

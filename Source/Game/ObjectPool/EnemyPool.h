// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyEnemy.h"
#include "ObjectPool.h"
#include "EnemyPool.generated.h"

class AMyCharacter;


USTRUCT()
struct FEnemyMap
{
	GENERATED_BODY()

public:
	FEnemyMap()
		: DefaultEnemyQueue(MakeShareable(new TQueue<AMyEnemy*>()))
		, EnemySmallQueue(MakeShareable(new TQueue<AMyEnemy*>()))
		, EnemyBossQueue(MakeShareable(new TQueue<AMyEnemy*>()))
	{}

	//~FEnemyMap()
	//{
	//	delete DefaultEnemyQueue;
	//	delete EnemySmallQueue;
	//	delete EnemyBossQueue;
	//}

	TSharedPtr<TQueue<AMyEnemy*>> operator[](EENEMY_TYPE EnemyType) const
	{
		switch (EnemyType)
		{
		case EENEMY_TYPE::ET_DEFAULT:
			return DefaultEnemyQueue;
			break;
		case EENEMY_TYPE::ET_SMALL:
			return EnemySmallQueue;
			break;
		case EENEMY_TYPE::ET_BOSS:
			return EnemyBossQueue;
			break;
		default:
			return DefaultEnemyQueue;
			break;
		}
	}

	TSharedPtr<TQueue<AMyEnemy*>> DefaultEnemyQueue;
	TSharedPtr<TQueue<AMyEnemy*>> EnemySmallQueue;
	TSharedPtr<TQueue<AMyEnemy*>> EnemyBossQueue;
};


/**
 * 
 */
UCLASS()
class GAME_API UEnemyPool : public UObjectPool
{
	GENERATED_BODY()

public:
	UEnemyPool();

	void BeginPlay();

	bool SpawnEnemy(EENEMY_TYPE EnemyType);
	void ReturnEnemy(EENEMY_TYPE EnemyType, AMyEnemy* ReturnedEnemy);
	
public:
	int32 MaxTotalEnemyCount = 3;

	TMap<EENEMY_TYPE, int> MaxEnemyCount;
	int32 CurrentEnemyCount = 0;

	int EnemyTypeCount = 3;

	//TMap<EENEMY_TYPE, TQueue<AMyEnemy*>*> CanSpawnEnemyPool;
	AMyCharacter* MyCharacter;

	float SpawnRadius = 500.f;


	FEnemyMap CanSpawnEnemyPool;

private:
	// Enemy
	UPROPERTY(VisibleAnywhere)
		TSubclassOf<AMyEnemy> EnemyClass;

	UPROPERTY(VisibleAnywhere)
		TSubclassOf<class AEnemy_Small> EnemySmallClass;

	UPROPERTY(VisibleAnywhere)
		TSubclassOf<class AEnemy_Boss> EnemyBossClass;
};

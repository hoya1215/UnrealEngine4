// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyEvent.generated.h"


class UBoxComponent;
class AMyEnemy;


UCLASS()
class GAME_API AEnemyEvent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyEvent();
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnCharacterBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnCharacterEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



	void SpawnEnemy();
	


	

	

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* Trigger;


	// Enemy
	UPROPERTY(VisibleAnywhere)
		TSubclassOf<AMyEnemy> EnemyClass;

	UPROPERTY(VisibleAnywhere)
		TSubclassOf<class AEnemy_Small> EnemySmallClass;

	UPROPERTY(VisibleAnywhere)
		TSubclassOf<class AEnemy_Boss> EnemyBossClass;

	TArray<int32> EnemyTypeCount;
	TArray<int32> MaxEnemyTypeCount;

	FTimerHandle EnemyTimerHandle;

	float SpawnInterval = 3.f;
	float SpawnRadius = 500.f;



	int32 CurrentEnemyCount = 0;
	int32 MaxEnemyCount = 1;

private:

};

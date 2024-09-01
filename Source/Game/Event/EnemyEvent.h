// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyEvent.generated.h"


class UBoxComponent;
class AMyEnemy;
class UEnemyPool;
class APoolStorage;


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
	

	UEnemyPool* GetEnemyPool() { return EnemyPool; }
	

	

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* Trigger;


	FTimerHandle EnemyTimerHandle;

	float SpawnInterval = 3.f;




private:
	UPROPERTY()
		UEnemyPool* EnemyPool;

	UPROPERTY()
		class UMyGameInstance* GameInstance;


};

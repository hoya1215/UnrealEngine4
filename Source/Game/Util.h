// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "MyGameModeBase.h"
#include "MyHUD.h"
#include "Engine/World.h"
#include "CoreMinimal.h"

/**
 * 
 */

class Util
{
public:
	static void SetGravity(AActor* Actor, bool gravity)
	{
		UStaticMeshComponent* MeshComponent = Cast<UStaticMeshComponent>(Actor->GetRootComponent());
		if (MeshComponent)
		{
			MeshComponent->SetEnableGravity(gravity);
		}
	}

	static void PlaySound(const UObject* Object, USoundBase* Sound, FVector Location)
	{
		UGameplayStatics::PlaySoundAtLocation(Object, Sound, Location);
	}

	static AMyCharacter* GetMyCharacter(UWorld* World)
	{
		AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(World, 0));

		return MyCharacter;
	}

	static UMyHUD* GetHUD(UWorld* World)
	{
		AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(World));
		return GameMode->Widget;
	}
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
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
};

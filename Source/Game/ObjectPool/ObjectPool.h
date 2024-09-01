// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectPool.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UObjectPool : public UObject
{
	GENERATED_BODY()
	
public:
	UObjectPool();

public:
	FVector StoreLocation;
};

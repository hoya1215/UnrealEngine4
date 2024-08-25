// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SoundManager.generated.h"

class UAudioComponent;
class USoundCue;
/**
 * 
 */
UCLASS()
class GAME_API USoundManager : public UObject
{
	GENERATED_BODY()
	
public:
	USoundManager();

	void PlayBackGroundMusic();


public:

	UPROPERTY()
		UAudioComponent* AudioComponent;

	UPROPERTY()
		USoundCue* BackGroundMusic;

	//UPROPERTY()
	//	USoundCue* BackGroundMusic;

	//UPROPERTY()
	//	USoundCue* BackGroundMusic;
};

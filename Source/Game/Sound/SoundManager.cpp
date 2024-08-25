// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundManager.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "Game/Util.h"

USoundManager::USoundManager()
{
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->bAutoActivate = false;

	BackGroundMusic = LoadObject<USoundCue>(nullptr, TEXT("SoundCue'/Game/Custom/Sound/Starter_Music_Cue.Starter_Music_Cue'"));

	//AudioComponent->RegisterComponentWithWorld(GEngine->GetWorld());
}

void USoundManager::PlayBackGroundMusic()
{
	//if (BackGroundMusic)
	//{
	//	AudioComponent->RegisterComponent();
	//	AudioComponent->SetSound(BackGroundMusic);
	//	AudioComponent->Play();
	//}

	Util::PlaySound(this, BackGroundMusic, FVector::ZeroVector);
}
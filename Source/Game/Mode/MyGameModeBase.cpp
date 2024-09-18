// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"
#include "FPSHUD.h"
#include "MyHUD.h"
#include "MyEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy_Small.h"
#include "Enemy_Boss.h"
#include "Gun.h"
#include "Sword.h"
#include "FireGun.h"
#include "Particles/ParticleSystemComponent.h"
#include "Sound/SoundManager.h"
#include "Util.h"
#include "Sound/SoundCue.h"
#include "ItemPool.h"
#include "PoolStorage.h"
#include "UIManager.h"

AMyGameModeBase::AMyGameModeBase()
{
	ConstructorHelpers::FClassFinder<AMyCharacter> BP_Character(TEXT("Blueprint'/Game/Custom/Blueprint/BP_MyCharacter.BP_MyCharacter_C'"));
	if (BP_Character.Succeeded())
		DefaultPawnClass = BP_Character.Class;

	ConstructorHelpers::FClassFinder<AFPSHUD> HUD(TEXT("Blueprint'/Game/Custom/Blueprint/BP_FPSHUD.BP_FPSHUD_C'"));
	if (HUD.Succeeded())
		HUDClass = HUD.Class;


	//static ConstructorHelpers::FClassFinder<UMyHUD> UI_HUD(TEXT("WidgetBlueprint'/Game/Custom/UI/WBP_HUD.WBP_HUD_C'"));
	//if (UI_HUD.Succeeded())
	//{
	//	HUD_Class = UI_HUD.Class;

	//	Widget = CreateWidget<UMyHUD>(GetWorld(), HUD_Class);
	//	if (Widget)
	//	{
	//		Widget->AddToViewport();
	//		//Widget->RemoveFromViewport(); Á¦°Å 
	//	}
	//}


	//EnemyTypeCount = EENEMY_TYPE::ET_ENEMY_TYPE_COUNT;

	static ConstructorHelpers::FClassFinder<AFireGun> FG(TEXT("Blueprint'/Game/Custom/Blueprint/BP_FireGun.BP_FireGun_C'"));
	if (FG.Succeeded())
	{
		FireGunClass = FG.Class;
	}

	BackGroundMusic = LoadObject<USoundCue>(nullptr, TEXT("SoundCue'/Game/Custom/Sound/Starter_Music_Cue.Starter_Music_Cue'"));
}

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();



	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UUIManager::Get()->BeginPlay(MyCharacter);
	//
	//Widget->SetCharacter(MyCharacter);


	auto Gun = GetWorld()->SpawnActor<AGun>(MyCharacter->GetActorLocation() + FVector(100.f, 0.f, 0.f), FRotator::ZeroRotator);
	auto Sword = GetWorld()->SpawnActor<ASword>(MyCharacter->GetActorLocation() + FVector(100.f, 0.f, 0.f), FRotator::ZeroRotator);
	auto FireGun = GetWorld()->SpawnActor<AFireGun>(FireGunClass, MyCharacter->GetActorLocation() + FVector(100.f, 0.f, 0.f), FRotator::ZeroRotator);
	FireGun->EffectComponent->Deactivate();

	//GetWorldTimerManager().SetTimer(EnemyTimerHandle, this, &AMyGameModeBase::SpawnEnemy, SpawnInterval, true);

	// Sound
	//UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetGameInstance());
	//GameInstance->GetSoundManager()->PlayBackGroundMusic();
	Util::PlaySound(this, BackGroundMusic, FVector::ZeroVector);

}




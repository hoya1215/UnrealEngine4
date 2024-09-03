// Fill out your copyright notice in the Description page of Project Settings.


#include "FireGun.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInterface.h"
#include "MyGameInstance.h"
#include "Sound/SoundCue.h"

AFireGun::AFireGun()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/FPS_Weapon_Bundle/Weapons/Meshes/KA_Val/SM_KA_Val_X.SM_KA_Val_X'"));
	if (SM.Succeeded())
		StaticMesh->SetStaticMesh(SM.Object);

	RootComponent = StaticMesh;

	StaticMesh->SetCollisionProfileName(TEXT("Gun"));
	Trigger->SetCollisionProfileName(TEXT("Gun"));
	Trigger->SetBoxExtent(FVector(30.f, 30.f, 30.f));
	Trigger->SetupAttachment(StaticMesh);

	//SetActorLocation(FVector(0.f, 10.f, 200.f));
	//RelativeRotation = FRotator(10.5f, -25.5f, -16.f);
	RelativeRotation = FRotator(0.f, 0.f, 0.f);

	EffectComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));

	ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/Realistic_Starter_VFX_Pack_Vol2/Particles/Fire/P_flamethrower.P_Flamethrower'"));
	if (PS.Succeeded())
	{
		Effect = PS.Object;
		EffectComponent->SetTemplate(Effect);
	}
	EffectComponent->Deactivate();

	EffectComponent->SetupAttachment(StaticMesh);


	EquipmentType = EEQUIPMENT_TYPE::SUB;

	//UTexture2D* SubTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/FireGun.FireGun'"));
	//ItemTexture = MakeShareable(SubTexture);

	WeaponState = 1;
	
	ConstructorHelpers::FObjectFinder<UMaterialInterface> MI(TEXT("Material'/Game/Custom/Resources/FireGun_Mat.FireGun_Mat'"));
	if (MI.Succeeded())
	{
		MaterialTexture = MI.Object;
	}

	ItemInfo.ItemName = FName(TEXT("FireGun"));
	ItemClass = AFireGun::StaticClass();

	AttackSound = LoadObject<USoundCue>(nullptr, TEXT("SoundCue'/Game/Custom/Sound/Smoke01_Cue.Smoke01_Cue'"));
}

void AFireGun::BeginPlay()
{
	Super::BeginPlay();

	EffectComponent->Deactivate();



}
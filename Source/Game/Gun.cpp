// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "MyCharacter.h"
#include "InventoryWidget.h"

// Sets default values
AGun::AGun()
{

	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GUN"));


	ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/FPS_Weapon_Bundle/Weapons/Meshes/Ka47/SM_KA47_X.SM_KA47_X'"));
	if (SM.Succeeded())
		StaticMesh->SetStaticMesh(SM.Object);

	ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (PS.Succeeded())
		Effect = PS.Object;

	// Ãæµ¹
	StaticMesh->SetCollisionProfileName(TEXT("Gun"));
	Trigger->SetCollisionProfileName(TEXT("Gun"));
	Trigger->SetBoxExtent(FVector(30.f, 30.f, 30.f));

	RootComponent = StaticMesh;
	Trigger->SetupAttachment(StaticMesh);

	SetActorLocation(FVector(0.f, 10.f, 200.f));

	EquipmentType = EEQUIPMENT_TYPE::MAIN;

	UTexture2D* MainGunTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/KA47.KA47'"));
	ItemTexture = MainGunTexture;

	MaxBulletCount = 5;
	CurrentBulletCount = 0;

	WeaponState = 0;
}





// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "MyCharacter.h"
#include "InventoryWidget.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"
#include "Sound/SoundCue.h"

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
	RelativeRotation = FRotator(5.f, -29.f, 6.5f);

	EquipmentType = EEQUIPMENT_TYPE::MAIN;

	//UTexture2D* MainGunTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/Gun.Gun'"));
	//ItemTexture = MakeShareable(MainGunTexture);

	MaxBulletCount = 5;
	CurrentBulletCount = 0;

	WeaponState = 0;

	ConstructorHelpers::FObjectFinder<UMaterialInterface> MI(TEXT("Material'/Game/Custom/Resources/Gun_Mat.Gun_Mat'"));
	if (MI.Succeeded())
	{
		MaterialTexture = MI.Object;
	}

	ItemName = FName(TEXT("MainGun"));
	ItemClass = AGun::StaticClass();

	AttackSound = LoadObject<USoundCue>(nullptr, TEXT("SoundCue'/Game/Custom/Sound/Explosion_Cue.Explosion_Cue'"));

}

void AGun::BeginPlay()
{
	Super::BeginPlay();


	SetWeaponInfo(ItemName);

	//UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	//auto List = GameInstance->ItemList.Find(ItemName);
	//if (List == nullptr)
	//{
	//	GameInstance->ItemList.Add(ItemName, MakeTuple(ItemClass, 0));
	//	GameInstance->ItemTexture.Add(ItemName, ItemTexture);
	//}
}





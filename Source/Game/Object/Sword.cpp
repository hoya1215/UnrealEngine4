// Fill out your copyright notice in the Description page of Project Settings.


#include "Sword.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"
#include "Sound/SoundCue.h"

ASword::ASword()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Weapon_Pack/Mesh/Weapons/Weapons_Kit/SM_Sickle.SM_Sickle'"));
	if (SM.Succeeded())
		StaticMesh->SetStaticMesh(SM.Object);
	
	ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/Realistic_Starter_VFX_Pack_Vol2/Particles/Blood/P_Blood_Splat_Cone.P_Blood_Splat_Cone'"));
	if (PS.Succeeded())
		Effect = PS.Object;

	RootComponent = StaticMesh;
	Trigger->SetupAttachment(StaticMesh);
	
	RelativeRotation = FRotator(-30.f, 20.f, -55.f);

	StaticMesh->SetCollisionProfileName(TEXT("Gun"));
	Trigger->SetCollisionProfileName(TEXT("Gun"));

	EquipmentType = EEQUIPMENT_TYPE::OTHER;

	//UTexture2D* SwordTexture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Custom/Resources/Sickle.Sickle'"));
	//ItemTexture = MakeShareable(SwordTexture);

	WeaponState = 2;

	ConstructorHelpers::FObjectFinder<UMaterialInterface> MI(TEXT("Material'/Game/Custom/Resources/Sickle_Mat.Sickle_Mat'"));
	if (MI.Succeeded())
	{
		MaterialTexture = MI.Object;
	}
	
	ItemInfo.ItemName = FName(TEXT("Sword"));
	ItemClass = ASword::StaticClass();



	AttackSound = LoadObject<USoundCue>(nullptr, TEXT("	SoundCue'/Game/Custom/Sound/voice_male_c_effort_short_07_Cue.voice_male_c_effort_short_07_Cue'"));
}

void ASword::BeginPlay()
{
	Super::BeginPlay();

}
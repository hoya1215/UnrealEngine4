// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Character_Tag.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ACharacter_Tag::ACharacter_Tag()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (SM.Succeeded())
		GetMesh()->SetSkeletalMesh(SM.Object);

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	EffectComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));

	ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/FXVarietyPack/Particles/P_ky_magicCircle1.P_ky_magicCircle1'"));
	if (PS.Succeeded())
	{
		Effect = PS.Object;
		EffectComponent->SetTemplate(Effect);
	}
	

	EffectComponent->SetupAttachment(GetMesh());
	

	SetActorTickEnabled(false);
}

// Called when the game starts or when spawned
void ACharacter_Tag::BeginPlay()
{
	Super::BeginPlay();
	EffectComponent->Deactivate();
}

// Called every frame
void ACharacter_Tag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacter_Tag::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


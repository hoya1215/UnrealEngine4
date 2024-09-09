// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Character_Tag.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "DrawDebugHelpers.h"
#include "MyCharacter.h"
#include "MyGameInstance.h"
#include "Util.h"
#include "MyCharacterStatComponent.h"
#include "MyEnemy.h"

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

void ACharacter_Tag::Attack()
{
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);

	float Range = 200.0f;
	float Radius = 50.f;

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * Range,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel3,
		FCollisionShape::MakeSphere(Radius),
		Params
	);

	// 디버거용 그림
	FVector Vec = GetActorForwardVector() * Range;
	FVector Center = GetActorLocation() + Vec * 0.5f;
	float HalfHeight = Range * 0.5f + Radius;
	FQuat Rotation = FRotationMatrix::MakeFromZ(Vec).ToQuat();
	FColor DrawColor = FColor::Red;

	

	if (bResult && HitResult.Actor.IsValid())
	{
		AMyEnemy* Enemy = Cast<AMyEnemy>(HitResult.Actor);
		if (Enemy)
		{
			AMyCharacter* MyCharacter = Util::GetMyCharacter(GetWorld());
			UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetGameInstance());
			auto CharacterStatData = GameInstance->GetStatData(MyCharacter->Stat->GetLevel());
			int CharacterPower = CharacterStatData->Level;

			FDamageEvent event;
			HitResult.Actor->TakeDamage(CharacterPower, event, GetController(), this);

			DrawColor = FColor::Green;
		}

	}

	DrawDebugCapsule(GetWorld(), Center, HalfHeight, Radius, Rotation, DrawColor, false, 2.f);
}


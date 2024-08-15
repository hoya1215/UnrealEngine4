// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemy.h"
#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Gun.h"
#include "Bullet.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "MyEnemy.h"
#include "MyCharacterStatComponent.h"
#include "MyGameModeBase.h"
#include "MyHUD.h"
#include "Components/TextBlock.h"
#include "Money.h"
#include "InventoryComponent.h"
#include "Components/WidgetComponent.h"
#include "InventoryWidget.h"
#include "EnemyController.h"
#include "EnemyAnimInstance.h"

// Sets default values
AMyEnemy::AMyEnemy()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (SM.Succeeded())
		GetMesh()->SetSkeletalMesh(SM.Object);

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.f), FRotator(0.0f, 0.f, 0.f));

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	Stat = CreateDefaultSubobject<UMyCharacterStatComponent>(TEXT("Stat"));


	AIControllerClass = AEnemyController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	EnemyType = EENEMY_TYPE::ET_DEFAULT;

}

void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();

	EnemyAnimInstance = Cast<UEnemyAnimInstance>(GetMesh()->GetAnimInstance());
}

void AMyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);





	int32 CurrentHp = Stat->GetHp();
	if (CurrentHp <= 0)
	{
		auto Money = GetWorld()->SpawnActor<AMoney>(GetActorLocation(), FRotator::ZeroRotator);
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SetActorTickEnabled(false);

		GetWorldTimerManager().SetTimer(DieTimer, this, &AMyEnemy::Die, DieTime, true);
	}


	if (EnemyAnimInstance)
	{
		EnemyAnimInstance->AttackEnd.AddLambda([this]()
			{
				IsAttack = false;
			});
	}

}


float AMyEnemy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Stat->OnAttacked(DamageAmount);

	return DamageAmount;
}


void AMyEnemy::Attack()
{
	IsAttack = true;

	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);

	float Range = 200.0f;
	float Radius = 50.f;

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * Range,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel6,
		FCollisionShape::MakeSphere(Radius),
		Params
	);

	// 디버거용 그림
	FVector Vec = GetActorForwardVector() * Range;
	FVector Center = GetActorLocation() + Vec * 0.5f;
	float HalfHeight = Range * 0.5f + Radius;
	FQuat Rotation = FRotationMatrix::MakeFromZ(Vec).ToQuat();
	FColor DrawColor;
	if (bResult)
		DrawColor = FColor::Green;
	else
		DrawColor = FColor::Red;

	DrawDebugCapsule(GetWorld(), Center, HalfHeight, Radius, Rotation, DrawColor, false, 2.f);

	if (bResult && HitResult.Actor.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Enemy Attack"));

		FDamageEvent event;
		HitResult.Actor->TakeDamage(Stat->GetPower(), event, GetController(), this);
	}



}


void AMyEnemy::Die()
{
	int32 EnemyTypeIndex = GetEnemyTypeIndex(EnemyType);

	if (EnemyTypeIndex == -1)
		return;

	AMyGameModeBase* GameModeBase = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameModeBase && GameModeBase->EnemyTypeCount[EnemyTypeIndex] > 0)
	{
		GameModeBase->EnemyTypeCount[EnemyTypeIndex]--;
	}

	AEnemyController* AIController = Cast<AEnemyController>(GetController());
	if (AIController)
	{
		AIController->OnUnPossess();
		//AIController->Destroy();
	}
	
	Destroy();
}

int32 AMyEnemy::GetEnemyTypeIndex(EENEMY_TYPE EEnemyType)
{
	switch (EEnemyType)
	{
	case EENEMY_TYPE::ET_DEFAULT:
		return 0;
		break;
	case EENEMY_TYPE::ET_SMALL:
		return 1;
		break;
	case EENEMY_TYPE::ET_BOSS:
		return 2;
		break;
	}

	return -1;
}









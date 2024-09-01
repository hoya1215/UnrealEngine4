// Fill out your copyright notice in the Description page of Project Settings.


#include "Pet.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PetController.h"
#include "Components/CapsuleComponent.h"
#include "MyEnemy.h"
#include "Item.h"
#include "DrawDebugHelpers.h"
#include "Util.h"
#include "MyCharacter.h"
#include "PetController.h"
#include "BehaviorTree/BehaviorTree.h"


APet::APet()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	PetName = FName(TEXT("Pet"));

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/FourEvilDragonsHP/Meshes/DrangonTheSoulEater/DragonTheSoulEaterSK.DragonTheSoulEaterSK'"));
	if (SM.Succeeded())
		SkeletalMesh->SetSkeletalMesh(SM.Object);

	ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/FXVarietyPack/Particles/P_ky_ThunderBallHit.P_ky_ThunderBallHit'"));
	if (PS.Succeeded())
		AttackEffect = PS.Object;

	RootComponent = SkeletalMesh;
	GetCapsuleComponent()->SetupAttachment(SkeletalMesh);

	SetActorScale3D(FVector(1.f, 1.f, 1.f));


	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pet"));

	
	//AIControllerClass = APetController::StaticClass();
	//AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

}


void APet::BeginPlay()
{
	Super::BeginPlay();
	SetPetInfo(PetName);
	
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	MyCharacter->CharacterDie.AddUObject(this, &APet::Stop);
	MyCharacter->CharacterRevive.AddUObject(this, &APet::ReStart);

}


void APet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PetInfo.bCanAttack)
	{
		SearchEnemy();

		if (EnemyTarget)
		{
			bIsAttacking = true;
		}
		else
		{
			bIsAttacking = false;
		}
	}

	if(PetInfo.bCanMagnet)
		SearchItem();
}


void APet::Attack()
{


	if (IsValid(EnemyTarget))
	{
		// 파이어볼 쏘기
		if (AttackEffect)
		{
			EnemyLocation = EnemyTarget->GetActorLocation();
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), AttackEffect, EnemyLocation, FRotator(0.f), true);
			//GetWorld()->GetTimerManager().SetTimer(EffectTimer, this, &APet::AttackEffectBegin, false);
		}

		FDamageEvent DamageEvent;
		EnemyTarget->TakeDamage(this->Power, DamageEvent, GetController(), this);
	}
}

void APet::SearchEnemy()
{


		TArray<FOverlapResult> OverlapResults;
		FCollisionQueryParams QueryParams(NAME_None, false, this);

		bool bResult = GetWorld()->OverlapMultiByChannel(
			OverlapResults,
			GetActorLocation(),
			FQuat::Identity,
			ECollisionChannel::ECC_GameTraceChannel6, // -> Enemy 채널로 
			FCollisionShape::MakeSphere(PetInfo.AttackRange),
			QueryParams);



		if (bResult)
		{
			for (auto& OverlapResult : OverlapResults)
			{
				AMyEnemy* Enemy = Cast<AMyEnemy>(OverlapResult.GetActor());

				if (Enemy && Enemy->bSpawned)
				{
					EnemyLocation = Enemy->GetActorLocation();
					FVector Direction = (GetActorLocation() - Enemy->GetActorLocation()).GetSafeNormal();
					FRotator NewRotation = FRotationMatrix::MakeFromX(Direction).Rotator();
					SetActorRotation(FRotator(0.f, NewRotation.Yaw + 90.f, 0.f));
					EnemyTarget = Enemy;

					return;
				}
			}

			EnemyTarget = nullptr;
		}
		else
		{
			EnemyTarget = nullptr;
		}

}

void APet::SearchItem()
{

		UWorld* World = GetWorld();
		FVector Center = GetActorLocation();
		//float SearchRadius = Pet->AttackArrange;
		float SearchRadius = MagnetArrange;

		if (World == nullptr)
			return;

		TArray<FOverlapResult> OverlapResults;
		FCollisionQueryParams QueryParams(NAME_None, false, this);

		bool bResult = World->OverlapMultiByChannel(
			OverlapResults,
			Center,
			FQuat::Identity,
			ECollisionChannel::ECC_GameTraceChannel4, // -> Enemy 채널로 
			FCollisionShape::MakeSphere(SearchRadius),
			QueryParams);



		if (bResult)
		{
			for (auto& OverlapResult : OverlapResults)
			{
				AItem* CurrentItem = Cast<AItem>(OverlapResult.GetActor());

				if (CurrentItem && CurrentItem->bCanMagnet)
				{
					Util::SetGravity(CurrentItem, false);
					//DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Green, false, 0.2f);
					MagnetItem(CurrentItem);

				}
			}
		}


		//DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Red, false, 0.2f);
}

void APet::MagnetItem(AItem* Item)
{
	FVector Direction = (GetActorLocation() - Item->GetActorLocation()).GetSafeNormal();
	FVector NewLocation = Item->GetActorLocation() + Direction * 2.0;
	Item->SetActorLocation(NewLocation);
}

void APet::AttackEffectBegin()
{
	AttackEffectComponent = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), AttackEffect, EnemyLocation, FRotator(0.f), true);

	GetWorld()->GetTimerManager().SetTimer(EffectTimer, this, &APet::AttackEffectEnd, 2.f, false);
}

void APet::AttackEffectEnd()
{
	if (AttackEffectComponent)
	{
		AttackEffectComponent->DestroyComponent();
		AttackEffectComponent = nullptr;
	}
}

void APet::Stop()
{
	SetActorTickEnabled(false);
	PetInfo.bCanAttack = false;
	PetInfo.bCanMagnet = false;

	bIsAttacking = false;


	//APetController* PetController = Cast<APetController>(GetController());
	//if (PetController)
	//{
	//	UBehaviorTreeComponent* BehaviorComp = Cast<UBehaviorTreeComponent>(PetController->BrainComponent);
	//	if (BehaviorComp)
	//	{
	//		BehaviorComp->StopLogic("Stopping Behavior Tree");
	//	}
	//}
}

void APet::ReStart()
{
	SetActorTickEnabled(true);
	PetInfo.bCanAttack = true;
	PetInfo.bCanMagnet = true;

	bIsAttacking = true;




	//APetController* PetController = Cast<APetController>(GetController());
	//if (PetController)
	//{
	//	PetController->RunBehaviorTree(PetController->GetBehaviorTree());
	//}
}

void APet::SetPetInfo(FName Name)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	auto PetData = MyGameInstance->GetPetData(Name);

	PetInfo.bCanAttack = PetData->bCanAttack;
	PetInfo.bCanMagnet = PetData->bCanMagnet;
	PetInfo.Power = PetData->Power;
	PetInfo.AttackRange = PetData->AttackRange;
	PetInfo.MagnetRange = PetData->MagnetRange;
	PetInfo.AttackSpeed = PetData->AttackSpeed;
}
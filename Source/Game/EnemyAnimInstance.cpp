// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyEnemy.h"
#include "GameFramework/Character.h"
#include "MyCharacterStatComponent.h"
#include "Enemy_Boss.h"
#include "Rock.h"


void UEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		CurrentEnemy = Cast<AMyEnemy>(Pawn);
	}
}

void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Enemy = Cast<AMyEnemy>(Pawn);
		if (Enemy)
		{
			IsFalling = Enemy->GetMovementComponent()->IsFalling();
			IsWalking = Enemy->IsWalking;
			IsAttack = Enemy->IsAttack;
			IsPicking = Enemy->IsPicking;
			Hp = Enemy->Stat->GetHp();
		}
	}
}

void UEnemyAnimInstance::AnimNotify_AttackHit()
{
	auto Pawn = TryGetPawnOwner();
	auto Enemy = Cast<AMyEnemy>(Pawn);
	Enemy->Attack();
}

void UEnemyAnimInstance::AnimNotify_AttackEnd()
{
	AttackEnd.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Attack End"));
	IsAttack = false;
}

void UEnemyAnimInstance::AnimNotify_RockPick()
{
	IsPicking = false;
	auto Pawn = TryGetPawnOwner();
	auto Enemy = Cast<AEnemy_Boss>(Pawn);
	if (Enemy)
	{
		Enemy->IsPicking = false;
		// 돌 손에 옮기기
		if (Enemy->MyRock)
		{
			FName RockSocket(TEXT("Boss_R_Hand"));
			Enemy->MyRock->AttachToComponent(Enemy->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
				RockSocket);
		}

	}
}

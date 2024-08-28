// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_EnemyAttack.h"
#include "EnemyController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "MyEnemy.h"
#include "EnemyAnimInstance.h"

UBTTask_EnemyAttack::UBTTask_EnemyAttack()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_EnemyAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyEnemy = Cast<AMyEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (MyEnemy == nullptr)
		return EBTNodeResult::Failed;

	// Enemy 어택 함수 넣기
	MyEnemy->IsAttack = true;
	//MyEnemy
	bIsAttack = true;

	// 공격 끝나면 false 로 바꿔주기
	//bIsAttack = false;
	UEnemyAnimInstance* Anim = Cast< UEnemyAnimInstance>(MyEnemy->GetMesh()->GetAnimInstance());
	if (Anim)
	{
		Anim->AttackEnd.AddLambda([this]()
		{
			bIsAttack = false;
		});
	}

	return Result;
}

void UBTTask_EnemyAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (bIsAttack == false)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
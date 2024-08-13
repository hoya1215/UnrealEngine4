// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PetAttack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "Pet.h"
#include "PetAnimInstance.h"
#include "PetController.h"

UBTTask_PetAttack::UBTTask_PetAttack()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_PetAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyPet = Cast<APet>(OwnerComp.GetAIOwner()->GetPawn());
	if (MyPet == nullptr)
		return EBTNodeResult::Failed;

	// Enemy 어택 함수 넣기
	MyPet->bIsAttacking = true;
	//MyEnemy
	bIsAttack = true;

	// 공격 끝나면 false 로 바꿔주기
	UPetAnimInstance* Anim = Cast< UPetAnimInstance>(MyPet->GetMesh()->GetAnimInstance());
	if (Anim)
	{
		Anim->AttackEnd.AddLambda([this]()
			{
				bIsAttack = false;
			});
	}

	return Result;
}

void UBTTask_PetAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (bIsAttack == false)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
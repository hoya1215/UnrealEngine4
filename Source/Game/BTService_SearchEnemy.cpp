// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SearchEnemy.h"
#include "PetController.h"
#include "Pet.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "MyEnemy.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"

UBTService_SearchEnemy::UBTService_SearchEnemy()
{
	NodeName = TEXT("SearchEnemy");
	// 1초마다 간격
	Interval = 1.0f;
}

void UBTService_SearchEnemy::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);


	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn)
	{
		UWorld* World = CurrentPawn->GetWorld();
		FVector Center = CurrentPawn->GetActorLocation();
		auto Pet = Cast<APet>(CurrentPawn);
		//float SearchRadius = Pet->AttackArrange;
		float SearchRadius = 300.f;

		if (World == nullptr)
			return;

		TArray<FOverlapResult> OverlapResults;
		FCollisionQueryParams QueryParams(NAME_None, false, Pet);

		bool bResult = World->OverlapMultiByChannel(
			OverlapResults,
			Center,
			FQuat::Identity,
			ECollisionChannel::ECC_GameTraceChannel6, // -> Enemy 채널로 
			FCollisionShape::MakeSphere(SearchRadius),
			QueryParams);



		if (bResult)
		{
			for (auto& OverlapResult : OverlapResults)
			{
				AMyEnemy* Enemy = Cast<AMyEnemy>(OverlapResult.GetActor());

				if (Enemy)
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), Enemy);

					//DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Green, false, 0.2f);
					Pet->EnemyLocation = Enemy->GetActorLocation();
					FVector Direction = (Pet->GetActorLocation() - Enemy->GetActorLocation()).GetSafeNormal();
					FRotator NewRotation = FRotationMatrix::MakeFromX(Direction).Rotator();
					Pet->SetActorRotation(FRotator(0.f, NewRotation.Yaw + 90.f, 0.f ));
					Pet->EnemyTarget = Enemy;

					return;
				}
			}
		}
		else
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);

			//AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			//Pet->SetActorRotation(FRotator(0.f, -90.f, 0.f));
		}

		Pet->bIsAttacking = false;
		//DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Red, false, 0.2f);
	}
}
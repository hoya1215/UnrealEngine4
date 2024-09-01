// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SearchRock.h"
#include "Rock.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "AIController.h"
#include "MyEnemy.h"
#include "Enemy_Boss.h"

UBTService_SearchRock::UBTService_SearchRock()
{
	NodeName = TEXT("SerachRock");

	Interval = 0.1f;
}

void UBTService_SearchRock::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto CurrentEnemy = Cast<AEnemy_Boss>(OwnerComp.GetAIOwner()->GetPawn());
	if (CurrentEnemy)
	{
		UWorld* World = CurrentEnemy->GetWorld();
		FVector Center = CurrentEnemy->GetActorLocation();
		float SearchRadius = 100.f;

		if (World == nullptr)
			return;

		TArray<FOverlapResult> OverlapResults;
		FCollisionQueryParams QueryParams(NAME_None, false, CurrentEnemy);

		bool bResult = World->OverlapMultiByChannel(
			OverlapResults,
			Center,
			FQuat::Identity,
			ECollisionChannel::ECC_GameTraceChannel7,
			FCollisionShape::MakeSphere(SearchRadius),
			QueryParams);



		if (bResult)
		{
			for (auto& OverlapResult : OverlapResults)
			{
				AActor* OverlappedActor = OverlapResult.GetActor();

				ARock* CurrentRock = Cast<ARock>(OverlapResult.GetActor());
				OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("HaveRock"), true);
				OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsPicking"), true);

				DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Green, false, 0.2f);
				// 줍기 애니메이션 실행 -> notify 로 손에 부착 
				CurrentEnemy->IsPicking = true;
				CurrentEnemy->MyRock = CurrentRock;


				return;

			}
		}
		else
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);
		}

		DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Red, false, 0.2f);
	}
}
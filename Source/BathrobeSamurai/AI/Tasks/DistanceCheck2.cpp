// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "AI/TestChar/MyProjectCharacter.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "DistanceCheck2.h"

EBTNodeResult::Type UDistanceCheck2::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
	}

	for (TActorIterator<AMyProjectCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AMyProjectCharacter* PlayerCharacter = *ActorItr;

		if (PlayerCharacter)
		{
			FVector MyPosition = OwnerComp.GetOwner()->GetActorLocation();

			FVector TargPosition = PlayerCharacter->GetActorLocation();

			Distance = FVector::Dist(MyPosition, TargPosition) / 10.f;

			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Float>(BlackboardKey.GetSelectedKeyID(), Distance);

			GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Red, TEXT("Distance = ") + FString::SanitizeFloat(Distance));

			if (MaxDistance < Distance)
			{
				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}
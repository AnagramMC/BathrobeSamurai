// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "Arin/Arin.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "CheckDistance.h"

EBTNodeResult::Type UCheckDistance::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
	}

	for (TActorIterator<AArin> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AArin* PlayerCharacter = *ActorItr;

		if (PlayerCharacter)
		{
			FVector MyPosition = OwnerComp.GetOwner()->GetActorLocation();
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), MyPosition);

			FVector TargPosition = PlayerCharacter->GetActorLocation();

			Distance = FVector::Dist(MyPosition, TargPosition) / 10.f;
			GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Red, TEXT("Distance = ") + FString::SanitizeFloat(Distance));

			if (MaxDistance >= Distance)
			{
				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}



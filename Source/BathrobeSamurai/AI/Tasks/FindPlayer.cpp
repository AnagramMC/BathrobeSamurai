// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "Arin/Arin.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "FindPlayer.h"

EBTNodeResult::Type UFindPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), PlayerCharacter);

			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
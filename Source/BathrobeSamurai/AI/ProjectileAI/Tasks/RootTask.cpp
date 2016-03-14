// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "RootTask.h"

EBTNodeResult::Type URootTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (!GetWorld())
	{
		return EBTNodeResult::Failed;

	}

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	bool isRooted = Blackboard->GetValue<UBlackboardKeyType_Bool>("IsRooted");
	float Distance = Blackboard->GetValue<UBlackboardKeyType_Float>("Distance");

	if (Distance <= 1000.f && Distance > 500.f)
	{
		if (!isRooted)
		{
			Blackboard->SetValue<UBlackboardKeyType_Bool>(BlackboardKey.GetSelectedKeyID(), true);

			return EBTNodeResult::Succeeded;
		}
		else
		{
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
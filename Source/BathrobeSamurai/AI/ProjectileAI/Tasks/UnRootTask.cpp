// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "UnRootTask.h"

EBTNodeResult::Type UUnRootTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (!GetWorld())
	{
		return EBTNodeResult::Failed;

	}

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	bool isRooted = Blackboard->GetValue<UBlackboardKeyType_Bool>("IsRooted");

	if (isRooted)
	{
		Blackboard->SetValue<UBlackboardKeyType_Bool>(BlackboardKey.GetSelectedKeyID(), false);

		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
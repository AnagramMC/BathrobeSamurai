// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "AI/ProjectileAI/ProjectileAICharacter.h"
#include "FireProjectileTask.h"

EBTNodeResult::Type UFireProjectileTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (!GetWorld())
	{
		return EBTNodeResult::Failed;

	}

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	bool isRooted = Blackboard->GetValue<UBlackboardKeyType_Bool>("IsRooted");

	if (isRooted)
	{
		AController* AIController = Cast<AController>(OwnerComp.GetOwner());
		AProjectileAICharacter* RangedEnemy = Cast<AProjectileAICharacter>(AIController->GetPawn());

		if (RangedEnemy)
		{
			RangedEnemy->FireProjectile();
			GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
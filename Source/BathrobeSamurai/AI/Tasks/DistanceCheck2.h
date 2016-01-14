// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "DistanceCheck2.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API UDistanceCheck2 : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
		float MaxDistance = 100.f;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	float Distance = 0.f;
};

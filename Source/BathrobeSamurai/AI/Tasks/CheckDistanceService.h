// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "CheckDistanceService.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API UCheckDistanceService : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		FName TargetName;

	UPROPERTY(EditAnywhere)
		FName KeyName;

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	float Distance = 0.f;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BaseAIController.generated.h"

UCLASS()
class BATHROBESAMURAI_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	UBlackboardComponent* GetBlackboardComponent() { return BlackboardComponent; }

protected:
	UPROPERTY(VisibleAnywhere)
		UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere)
		UBlackboardComponent* BlackboardComponent;
};

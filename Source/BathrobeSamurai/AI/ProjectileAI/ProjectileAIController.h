// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/BaseAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ProjectileAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API AProjectileAIController : public ABaseAIController
{
	GENERATED_BODY()
	
	AProjectileAIController();

	virtual void Possess(APawn* Pawn) override;
};

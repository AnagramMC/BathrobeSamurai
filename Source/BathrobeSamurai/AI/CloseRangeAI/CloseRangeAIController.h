// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/BaseAIController.h"
#include "CloseRangeAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API ACloseRangeAIController : public ABaseAIController
{
	GENERATED_BODY()
	
	ACloseRangeAIController();

	virtual void Possess(APawn* Pawn) override;
};

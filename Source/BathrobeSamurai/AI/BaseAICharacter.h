// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BaseAICharacter.generated.h"

UCLASS()
class BATHROBESAMURAI_API ABaseAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		UBehaviorTree* BehaviorTree;

public:
	// Sets default values for this character's properties
	ABaseAICharacter();
};

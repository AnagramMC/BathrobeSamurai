// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BaseAICharacter.h"
#include "BaseAIController.h"

ABaseAIController::ABaseAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void ABaseAIController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	ABaseAICharacter* Character = Cast<ABaseAICharacter>(Pawn);
	if (Character && Character->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*Character->BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*Character->BehaviorTree);
	}
}
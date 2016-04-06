// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "TeraAICharacter.h"
#include "TeraAIController.h"

ATeraAIController::ATeraAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void ATeraAIController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	ATeraAICharacter* Character = Cast<ATeraAICharacter>(Pawn);
	if (Character && Character->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*Character->BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*Character->BehaviorTree);
	}
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "CloseRangeAICharacter.h"
#include "CloseRangeAIController.h"

ACloseRangeAIController::ACloseRangeAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void ACloseRangeAIController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	ACloseRangeAICharacter* Character = Cast<ACloseRangeAICharacter>(Pawn);
	if (Character && Character->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*Character->BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*Character->BehaviorTree);
	}
}
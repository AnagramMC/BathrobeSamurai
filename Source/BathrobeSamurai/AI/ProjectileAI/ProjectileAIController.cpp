// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "ProjectileAICharacter.h"
#include "ProjectileAIController.h"

AProjectileAIController::AProjectileAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AProjectileAIController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	AProjectileAICharacter* Character = Cast<AProjectileAICharacter>(Pawn);
	if (Character && Character->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*Character->BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*Character->BehaviorTree);
	}
}
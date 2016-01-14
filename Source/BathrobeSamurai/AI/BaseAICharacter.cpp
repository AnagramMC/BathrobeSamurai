// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BaseAIController.h"
#include "BaseAICharacter.h"


// Sets default values
ABaseAICharacter::ABaseAICharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = ABaseAIController::StaticClass();
}


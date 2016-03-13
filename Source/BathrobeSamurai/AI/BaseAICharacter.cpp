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

void ABaseAICharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ABaseAICharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

float ABaseAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	return 0.f;
}


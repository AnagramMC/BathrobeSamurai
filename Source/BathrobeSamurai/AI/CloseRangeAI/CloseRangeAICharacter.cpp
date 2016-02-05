// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "CloseRangeAICharacter.h"

void ACloseRangeAICharacter::EnemyInteract(AActor* Interactor)
{
	//
}

float ACloseRangeAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
	}

	if (Health <= 0)
	{
		if (DamageCauser)
		{
			AArin* Player = Cast<AArin>(DamageCauser);
			if (Player)
			{
				DestroySelf();
			}
		}
	}

	return ActualDamage;
}

void ACloseRangeAICharacter::DestroySelf()
{
	Destroy();
}
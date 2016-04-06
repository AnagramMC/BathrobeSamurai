// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "TeraAICharacter.h"

void ATeraAICharacter::EnemyInteract(AActor* Interactor)
{
	//
}

float ATeraAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
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

void ATeraAICharacter::DestroySelf()
{
	Destroy();
}
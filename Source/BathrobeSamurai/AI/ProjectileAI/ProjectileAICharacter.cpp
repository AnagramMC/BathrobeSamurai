// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "ProjectileAICharacter.h"

void AProjectileAICharacter::EnemyInteract(AActor* Interactor)
{
	//
}

void AProjectileAICharacter::FireProjectile()
{
	if (ProjectileClass != NULL)
	{
		const FRotator SpawnRotation = GetControlRotation() + ProjectilePitch;
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = GetActorLocation() + ProjectileOffset;

		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			World->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		}
	}
}

float AProjectileAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
	}

	if (Health <= 0)
	{
		/*if (DamageCauser)
		{
			AArin* Player = Cast<AArin>(DamageCauser);
			if (Player)
			{
				Player->killCount++;
				DestroySelf();
			}
		}*/

		DestroySelf();
	}

	return ActualDamage;
}

void AProjectileAICharacter::DestroySelf()
{
	Destroy();
}
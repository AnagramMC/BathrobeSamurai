// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "Kismet/KismetMathLibrary.h"
#include "ProjectileAICharacter.h"

void AProjectileAICharacter::EnemyInteract(AActor* Interactor)
{
	//
}

void AProjectileAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AActor* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (Player)
	{
		FRotator NewRot = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), Player->GetActorLocation());

		NewRot.Roll = 0.f;
		NewRot.Pitch = 0.f;

		//NewRot.Yaw += -90;

		this->SetActorRotation(NewRot);
	}
}

void AProjectileAICharacter::FireProjectile()
{
	if (ProjectileClass != NULL)
	{
		for (TActorIterator<AArin> Player(GetWorld()); Player; ++Player)
		{
			AArin* Arin = Cast<AArin>(*Player);

			float Distance = FVector::Dist(this->GetActorLocation(), Arin->GetActorLocation());

			ProjectilePitch.Pitch = -0.5 * (FMath::RadiansToDegrees(FMath::Asin((GetWorld()->GetDefaultGravityZ() * Distance) / (1200.f * 1200.f))));

			GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, FString::SanitizeFloat(ProjectilePitch.Pitch));
		}
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

void AProjectileAICharacter::DestroySelf()
{
	Destroy();
}
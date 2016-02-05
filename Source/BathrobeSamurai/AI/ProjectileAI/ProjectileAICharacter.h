// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/BaseAICharacter.h"
#include "Arin/Arin.h"
#include "AI/ProjectileAI/Projectile.h"
#include "ProjectileAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API AProjectileAICharacter : public ABaseAICharacter
{
	GENERATED_BODY()
	
protected:

	virtual void EnemyInteract(AActor* Interact) override;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> ProjectileClass;

	UFUNCTION()
		virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;


	void DestroySelf();

public:

	void FireProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		FVector ProjectileOffset;

	virtual void Tick(float DeltaTime) override;

private:

	uint8 Health = 10;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
	FRotator ProjectilePitch;
};

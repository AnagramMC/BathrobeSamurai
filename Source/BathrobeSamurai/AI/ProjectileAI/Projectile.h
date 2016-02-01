// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATHROBESAMURAI_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AProjectile();

	UPROPERTY(EditDefaultsOnly)
		UProjectileMovementComponent* Projectile;

private:

	float speedPower;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* Collider;

	UFUNCTION()
		virtual void OnActorOverlap(AActor* OtherActor);
};

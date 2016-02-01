// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "Arin/Arin.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	Collider->BodyInstance.SetCollisionProfileName("Projectile");
	Collider->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	Collider->CanCharacterStepUpOn = ECB_No;

	RootComponent = Collider;

	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	Projectile->UpdatedComponent = Collider;
	Projectile->InitialSpeed = 1200.f;
	Projectile->MaxSpeed = 1200.f;
	Projectile->bRotationFollowsVelocity = true;
	Projectile->bShouldBounce = false;

	OnActorBeginOverlap.AddDynamic(this, &AProjectile::OnActorOverlap);

	InitialLifeSpan = 5.0f;

}

void AProjectile::OnActorOverlap(AActor* OtherActor)
{
	if (OtherActor != GetOwner())
	{
		//this->Destroy();
		UGameplayStatics::ApplyDamage(OtherActor, 10.f, this->GetInstigatorController(), this, UDamageType::StaticClass());

		AArin* Player = Cast<AArin>(OtherActor);
	}
}


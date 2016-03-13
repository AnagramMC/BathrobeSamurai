// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BaseAICharacter.generated.h"

UCLASS()
class BATHROBESAMURAI_API ABaseAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		UBehaviorTree* BehaviorTree;

public:
	// Sets default values for this character's properties
	ABaseAICharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void EnemyInteract(AActor* Interactor) PURE_VIRTUAL(ABaseAICharacter::Interact, );

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float KnockbackAmount = 1.f;

	UPROPERTY(VisibleAnywhere)
	bool bIsHit = false;

	UPROPERTY(VisibleAnywhere)
	bool bIsDead = false;

protected:
	UFUNCTION()
		virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
};

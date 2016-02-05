// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/BaseAICharacter.h"
#include "Arin/Arin.h"
#include "CloseRangeAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API ACloseRangeAICharacter : public ABaseAICharacter
{
	GENERATED_BODY()
	
protected:
	virtual void EnemyInteract(AActor* Interact) override;

	UFUNCTION()
		virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	void DestroySelf();

private:
	uint8 Health = 10;
};

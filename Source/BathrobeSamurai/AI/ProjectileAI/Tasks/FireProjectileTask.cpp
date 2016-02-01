// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "AI/ProjectileAI/ProjectileAICharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "FireProjectileTask.h"

EBTNodeResult::Type UFireProjectileTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (!GetWorld())
	{
		return EBTNodeResult::Failed;

	}

	for (TActorIterator<AProjectileAICharacter> Enemy(GetWorld()); Enemy; ++Enemy)
	{
		AProjectileAICharacter* RangedEnemy = *Enemy;

		if (RangedEnemy)
		{

			AActor* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

			AController* AiController = Cast<AController>(OwnerComp.GetOwner());

			if (Player && AiController)
			{
				FRotator NewRot = UKismetMathLibrary::FindLookAtRotation(AiController->GetPawn()->GetActorLocation(), Player->GetActorLocation());


				NewRot.Roll = 0.f;
				NewRot.Pitch = 0.f;

				//NewRot.Yaw += -90;

				AiController->GetPawn()->SetActorRotation(NewRot);


				RangedEnemy->FireProjectile();
				GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));
				return EBTNodeResult::Succeeded;
			}
		}

		GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));

		return EBTNodeResult::Failed;
	}


	return EBTNodeResult::Failed;


}
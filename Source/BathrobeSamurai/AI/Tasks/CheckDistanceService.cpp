// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Arin/Arin.h"
#include "AI/BaseAIController.h"
#include "CheckDistanceService.h"

void UCheckDistanceService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	UObject* TargetObject = Blackboard->GetValue<UBlackboardKeyType_Object>(TargetName);

	AArin* PlayerCharacter = Cast<AArin>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	ABaseAIController* AIController = Cast<ABaseAIController>(Blackboard->GetOwner());

	if (AIController && PlayerCharacter)
	{
		Distance = FVector::Dist(PlayerCharacter->GetActorLocation(), AIController->GetPawn()->GetActorLocation());

		Blackboard->SetValue<UBlackboardKeyType_Float>(BlackboardKey.GetSelectedKeyID(), Distance);
	}

	GEngine->AddOnScreenDebugMessage(4, 1, FColor::Blue, TEXT("Ding"));
}





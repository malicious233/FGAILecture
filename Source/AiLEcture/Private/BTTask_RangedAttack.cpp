// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RangedAttack.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "DrawDebugHelpers.h"

UBTTask_RangedAttack::UBTTask_RangedAttack()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_RangedAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	TimeStamp = GetWorld()->GetTimeSeconds();
	PlayerRef = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(PlayerKey.SelectedKeyName));
	
	if (PlayerRef == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::InProgress;
	//return Super::ExecuteTask(OwnerComp, NodeMemory);
}

void UBTTask_RangedAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{

	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if ((GetWorld()->GetTimeSeconds() - TimeStamp) >= TimeBetweenShots)
	{
		//Fire
		Fire(OwnerComp.GetAIOwner()->GetPawn());


		

		if (AccumulatedShots >= ShotCount)
		{
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		}

		
	}

}

void UBTTask_RangedAttack::Fire(AActor* FiringActor)
{
	const FVector TargetPoint = (FiringActor->GetActorForwardVector() * ShotRange) + FiringActor->GetActorLocation();

	FHitResult Result;

	DrawDebugLine(GetWorld(), FiringActor->GetActorLocation(), TargetPoint, FColor::Green, true, 1.0f, 4, 4);
	if (GetWorld()->LineTraceSingleByChannel(Result, FiringActor->GetActorLocation(), TargetPoint, ECC_WorldDynamic))
	{
		if (Result.GetActor() == PlayerRef)
		{
			FDamageEvent Event;
			PlayerRef->TakeDamage(20.f, Event, FiringActor->GetInstigatorController(), FiringActor);
		}
	}

	TimeStamp = GetWorld()->GetTimeSeconds();

	//Add To Accumulator
	AccumulatedShots++;
}



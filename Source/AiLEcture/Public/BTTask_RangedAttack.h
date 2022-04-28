// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RangedAttack.generated.h"

/**
 * 
 */
UCLASS()
class AILECTURE_API UBTTask_RangedAttack : public UBTTaskNode
{
	GENERATED_BODY()

		UBTTask_RangedAttack();

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
		virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	void Fire(AActor* FiringActor);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector PlayerKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TimeBetweenShots = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ShotCount = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ShotRange = 500.f;

private:
	float TimeStamp = -1.0f;

	int32 AccumulatedShots = 0;

	UPROPERTY()
	AActor* PlayerRef = nullptr;
};

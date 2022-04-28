// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "FGAIController.generated.h"


/**
 * 
 */

class UAIPerceptionComponent;
class UBlackboardComponent;

UCLASS(Blueprintable)
class AILECTURE_API AFGAIController : public AAIController
{
	GENERATED_BODY()

	AFGAIController();

	UFUNCTION()
	void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	UAIPerceptionComponent* PerceptionComp = nullptr;

	UPROPERTY()
	UBlackboardComponent* BlackboardComp = nullptr;
	
};

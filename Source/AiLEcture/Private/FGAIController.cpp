// Fill out your copyright notice in the Description page of Project Settings.


#include "FGAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "GameFramework/Character.h"

AFGAIController::AFGAIController()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AFGAIController::OnPerceptionUpdated);
}

void AFGAIController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (ACharacter* PlayerCharacter = Cast<ACharacter>(Actor))
	{
		if (BlackboardComp == nullptr)
		{
			BlackboardComp = GetBlackboardComponent();
		}
			
		if (Stimulus.WasSuccessfullySensed())
		{
			BlackboardComp->SetValueAsObject("Player", Actor); //This is kinda cringe
			return;

			//Stimulus was found
		}

		BlackboardComp->ClearValue("Player");
		//Stimulus was lost

	}
}

void AFGAIController::BeginPlay()
{
	Super::BeginPlay();
	BlackboardComp = GetBlackboardComponent();
}


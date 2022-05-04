// Fill out your copyright notice in the Description page of Project Settings.


#include "FGAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

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
			//BlackboardComp->SetValueAsObject("Player", Actor); //This is kinda cringe
			BlackboardComp->SetValueAsBool("HasLOS", true);
			BlackboardComp->SetValueAsBool("Alert", true);
			BlackboardComp->ClearValue("LastSpottedLocation");
			return;

			//Stimulus was found
		}

		//Stimulus was lost
		Blackboard->SetValueAsVector("LastSpottedLocation", PlayerCharacter->GetActorLocation());
		BlackboardComp->SetValueAsBool("HasLOS", false);
		
		

	}
}

float AFGAIController::GetPlayerDistance()
{
	return FVector::Distance(PlayerRef->GetActorLocation(), GetPawn()->GetActorLocation());
}

void AFGAIController::BeginPlay()
{
	Super::BeginPlay();
	BlackboardComp = GetBlackboardComponent();
	BlackboardComp->SetValueAsObject("Player", UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}


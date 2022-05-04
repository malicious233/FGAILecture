

#include "FGGameplayDebuggerCategory.h"
#include "FGAIController.h"

FFGGameplayDebuggerCategory::FFGGameplayDebuggerCategory()
{
}

TSharedRef<FGameplayDebuggerCategory> FFGGameplayDebuggerCategory::MakeInstance()
{
	return MakeShareable(new FFGGameplayDebuggerCategory());
}

void FFGGameplayDebuggerCategory::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
	AFGAIController* Controller = Cast<AFGAIController>(DebugActor->GetInstigatorController());

	if (Controller == nullptr)
	{
		return;
	}

	Data.Distance = Controller->GetPlayerDistance();
}

void FFGGameplayDebuggerCategory::DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext)
{
	CanvasContext.Printf(TEXT("{green} Distance to player is: %s"), *FString::SanitizeFloat(Data.Distance));
}
#pragma once

#include "CoreMinimal.h"
#include "GameplayDebuggerCategory.h"

struct FDebugData
{
	float Distance = FLT_MAX;
};

class AILECTURE_API FFGGameplayDebuggerCategory : public FGameplayDebuggerCategory
{
public:
	FFGGameplayDebuggerCategory();

	static TSharedRef<FGameplayDebuggerCategory> MakeInstance();
	virtual void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;
	virtual void DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) override;
	FDebugData Data;

protected:
	
};
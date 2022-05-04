// Copyright Epic Games, Inc. All Rights Reserved.

#include "FGGameplayDebuggerCategory.h"
#include "GameplayDebugger.h"
#include "AiLEcture.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, AiLEcture, "AiLEcture" );
 
void FAiLEcture::StartupModule()
{
	IGameplayDebugger& GameplayDebugger = IGameplayDebugger::Get();
	GameplayDebugger.RegisterCategory("FGCustom", IGameplayDebugger::FOnGetCategory::CreateStatic(&FFGGameplayDebuggerCategory::MakeInstance));
	GameplayDebugger.NotifyCategoriesChanged();
}

void FAiLEcture::ShutdownModule()
{
	if (IGameplayDebugger::IsAvailable())
	{
		IGameplayDebugger& GameplayDebugger = IGameplayDebugger::Get();
		GameplayDebugger.UnregisterCategory("FGCustom");
	}
}
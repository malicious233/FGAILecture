// Copyright Epic Games, Inc. All Rights Reserved.

#include "AiLEctureGameMode.h"
#include "AiLEctureCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAiLEctureGameMode::AAiLEctureGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

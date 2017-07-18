// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ACTION_RTS.h"
#include "ACTION_RTSGameMode.h"
#include "ACTION_RTSPlayerController.h"
#include "ACTION_RTSCharacter.h"

AACTION_RTSGameMode::AACTION_RTSGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AACTION_RTSPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "ACTION_RTS.h"

#include "ARTS_Pawn.h"
#include "ARTS_Controller.h"

#include "ARTS_GameMode.h"


AARTS_GameMode::AARTS_GameMode()
{
	DefaultPawnClass = AARTS_Pawn::StaticClass();
	PlayerControllerClass = AARTS_Controller::StaticClass();
}


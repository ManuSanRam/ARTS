// Fill out your copyright notice in the Description page of Project Settings.

#include "ACTION_RTS.h"
#include "ARTS_Controller.h"

AARTS_Controller::AARTS_Controller()
{
	

}

void AARTS_Controller::PlayerTick(float DeltaTime)
{
	if (m_bRTS)
	{

	}
}

void AARTS_Controller::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// ------ CAM ------ //
	InputComponent->BindAction("ChangePersp",	IE_Pressed,		this,	&AARTS_Controller::ChangePersp); //Controller
	InputComponent->BindAction("PositionCam",	IE_Pressed,		this,	&AARTS_Controller::PositionCam); //Controller
	InputComponent->BindAction("SwitchCam",		IE_Pressed,		this,	&AARTS_Controller::SwitchCameras); //Controller

	InputComponent->BindAction("ZoomIn",		IE_Pressed,		m_PossCam,	&AARTS_Cam::ZoomIn); //Cam
	InputComponent->BindAction("ZoomOut",		IE_Pressed,		m_PossCam,	&AARTS_Cam::ZoomOut); //Cam

	InputComponent->BindAxis("CamPitch",		m_PossPawn,			&AARTS_Pawn::CamPitch); //Pawn
	InputComponent->BindAxis("CamYaw",			m_PossPawn,			&AARTS_Pawn::CamYaw); //Pawn

	// ------ PAWN ------ //
	InputComponent->BindAction("SetMovingPos",	IE_Pressed,		this,	&AARTS_Controller::SetMovingPos_P); //Controller
	InputComponent->BindAction("SetMovingPos",	IE_Released,	this,	&AARTS_Controller::SetMovingPos_R); //Controller

	InputComponent->BindAxis("MoveForward",		m_PossPawn,			&AARTS_Pawn::MoveForward); //Pawn
	InputComponent->BindAxis("MoveRight",		m_PossPawn,			&AARTS_Pawn::MoveRight); //Pawn

	InputComponent->BindAction("SelectPawns",	IE_Pressed,		this,	&AARTS_Controller::SelectPawns_P); //Controller
	InputComponent->BindAction("SelectPawns",	IE_Released,	this,	&AARTS_Controller::SelectPawns_R); //Controller
}

void AARTS_Controller::ChangePersp()
{
	m_bRTS = !m_bRTS;
}

void AARTS_Controller::PositionCam()
{

}

void AARTS_Controller::SwitchCameras()
{

}

void AARTS_Controller::SetMovingPos_P()
{

}

void AARTS_Controller::SetMovingPos_R()
{

}

void AARTS_Controller::SelectPawns_P()
{

}

void AARTS_Controller::SelectPawns_R()
{

}




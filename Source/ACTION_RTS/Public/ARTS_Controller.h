// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"

#include "ARTS_CamManager.h"
#include "ARTS_Cam.h"
#include "ARTS_Pawn.h"

#include "ARTS_Controller.generated.h"

/**
 * 
 */
UCLASS()
class ACTION_RTS_API AARTS_Controller : public APlayerController
{
	GENERATED_BODY()
public:
	AARTS_Controller();

	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	void ChangePersp();
	void PositionCam();
	void SwitchCameras();

	void SetMovingPos_P();
	void SetMovingPos_R();

	void SelectPawns_P();
	void SelectPawns_R();

	// If on, ACTION mode activated, else RTS mode is on...
	bool				m_bRTS;
	//
	UPROPERTY(VisibleAnywhere)
	AARTS_CamManager*	m_Manager;
	// Active cam to control
	UPROPERTY(VisibleAnywhere)
	AARTS_Cam*			m_PossCam;
	// Active pawn to be controlled
	UPROPERTY(VisibleAnywhere)
	AARTS_Pawn*			m_PossPawn;
};

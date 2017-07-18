// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "ARTS_Cam.h"

#include "ARTS_CamManager.generated.h"

UCLASS()
class ACTION_RTS_API AARTS_CamManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARTS_CamManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Add a cam to the cam list
	void AddCam(AARTS_Cam& _cam);
	// Remove a camera from the list
	void RemoveCam(AARTS_Cam& _cam);
	// Switch between cams on the list
	void SwitchCam(AARTS_Cam& _destCam);
	// Set a camera as the real cam, the one that renders to the screen
	void SetActiveCam(AARTS_Cam& _cam);

	void GetInitialCam(AARTS_Cam& _cam);

	bool					m_bSwitch;

	// List of cameras positioned by the player
	TArray<AARTS_Cam*>		m_CamList;
	// First camera to be pointed to
	AARTS_Cam*				m_InitialCam;
	// Cam to which to switch
	AARTS_Cam*				m_DestinationCam;
	// Active camera, point from where the world is rendered to screen
	AARTS_Cam*				m_ActiveCam;
	
};

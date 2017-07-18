// Fill out your copyright notice in the Description page of Project Settings.

#include "ACTION_RTS.h"
#include "ARTS_CamManager.h"


// Sets default values
AARTS_CamManager::AARTS_CamManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AARTS_CamManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARTS_CamManager::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	float SmoothBlendTime = 0.65f;

	if ( m_bSwitch && m_DestinationCam)
	{
		// Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if ((OurPlayerController->GetViewTarget() != m_DestinationCam) && (m_DestinationCam != nullptr))
			{
				SetActiveCam(*m_DestinationCam);
				// Blend smoothly to camera two.
				OurPlayerController->SetViewTarget(m_DestinationCam);
			}
		}
	}

}

void AARTS_CamManager::GetInitialCam(AARTS_Cam& _cam)
{
	AddCam(_cam);

	m_InitialCam = &_cam;
}

// Add a cam to the cam list
void AARTS_CamManager::AddCam(AARTS_Cam& _cam)
{

	m_CamList.Add(&_cam);
}

// Remove a camera from the list
void AARTS_CamManager::RemoveCam(AARTS_Cam& _cam)
{
	m_CamList.Remove(&_cam);
}

// Switch between cams on the list
void AARTS_CamManager::SwitchCam(AARTS_Cam& _destCam)
{
	m_bSwitch = true;

	for (int32 _i = 0; _i < m_CamList.Num(); ++_i)
	{
		if (m_CamList[_i]->m_ID == _destCam.m_ID)
		{
			m_DestinationCam = &_destCam;
		}
	}
}

// Set a camera as the real cam, the one that renders to the screen
void AARTS_CamManager::SetActiveCam(AARTS_Cam& _cam)
{
	m_ActiveCam = &_cam;
}



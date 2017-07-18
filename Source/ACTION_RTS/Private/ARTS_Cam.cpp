// Fill out your copyright notice in the Description page of Project Settings.

#include "ACTION_RTS.h"
#include "ARTS_Cam.h"



// Sets default values
AARTS_Cam::AARTS_Cam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CamArm"));
	m_SpringArm->SetupAttachment(RootComponent);
	m_SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 80.0f), FRotator(-60.0f, 0.0f, 0.0f));
	m_SpringArm->TargetArmLength = 650.f;
	m_SpringArm->bEnableCameraLag = true;
	m_SpringArm->CameraLagSpeed = 3.0f;

	m_Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCam"));
	m_Cam->SetupAttachment(m_SpringArm, USpringArmComponent::SocketName);

	m_ID = _idAssigner;
	++_idAssigner;
}

// Called when the game starts or when spawned
void AARTS_Cam::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARTS_Cam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_Zoom)
	{
		m_ZoomFactor += DeltaTime / 0.5f;         //Zoom in over half a second
	}
	else
	{
		m_ZoomFactor -= DeltaTime / 0.25f;        //Zoom out over a quarter of a second
	}
	m_ZoomFactor = FMath::Clamp<float>(m_ZoomFactor, 0.0f, 1.0f);
	//Blend our camera's FOV and our SpringArm's length based on ZoomFactor
	m_Cam->FieldOfView = FMath::Lerp<float>(90.0f, 60.0f, m_ZoomFactor);
	m_SpringArm->TargetArmLength = FMath::Lerp<float>(600.0f, 300.0f, m_ZoomFactor);
}

void AARTS_Cam::SetHeight(float _height)
{

}

// Set the rotation in x of the camera
void AARTS_Cam::SetRotation(float _rotation)
{

}

void AARTS_Cam::IntoACTION(AARTS_Pawn& _pawn)
{

}

void AARTS_Cam::IntoRTS(FVector _position)
{

}

//
void AARTS_Cam::ZoomIn()
{
	m_Zoom = true;
}
//
void AARTS_Cam::ZoomOut()
{
	m_Zoom = false;
}

void AARTS_Cam::MoveOnDirection()
{

}


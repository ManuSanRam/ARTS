// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "ARTS_Pawn.h"

#include "ARTS_Cam.generated.h"

UCLASS()
class ACTION_RTS_API AARTS_Cam : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARTS_Cam();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Set the height of the camera
	void SetHeight(float _height);
	// Set the rotation in x of the camera
	void SetRotation(float _rotation);

	void IntoACTION(AARTS_Pawn& _pawn);
	void IntoRTS(FVector _position);

	//
	void ZoomIn();
	//
	void ZoomOut();

	// ------ RTS ------
	// Move the camera along the direction the mouse moves on the screen
	void MoveOnDirection();

	uint32						m_ID;
	
	bool						m_Zoom;

	float						m_ZoomFactor;

	UPROPERTY(EditAnywhere)
	USpringArmComponent*		m_SpringArm;
	// Camera object that renders something on screen
	UCameraComponent*			m_Cam;
};

static uint32 _idAssigner = 0;

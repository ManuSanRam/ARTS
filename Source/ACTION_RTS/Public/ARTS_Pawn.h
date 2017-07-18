// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "ARTS_Pawn.generated.h"

UCLASS()
class ACTION_RTS_API AARTS_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AARTS_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// -------- RTS --------
	void MoveToClick();

	// ------ ACTION ------
	void MoveForward(float _axisVal);

	void MoveRight(float _axisVal);

	void CamPitch(float _axisVal);

	void CamYaw(float _axisVal);

	FVector				m_Movement;
	FVector				m_Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;
	UPROPERTY(EditAnywhere)
	USpringArmComponent*		m_SpringArm;
	// Camera object that renders something on screen
	UCameraComponent*			m_Cam;
};

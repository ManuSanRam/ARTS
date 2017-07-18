// Fill out your copyright notice in the Description page of Project Settings.

#include "ACTION_RTS.h"
#include "ARTS_Pawn.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"

// Sets default values
AARTS_Pawn::AARTS_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	m_SpringArm->SetupAttachment(RootComponent);
	m_SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-15.0f, 0.0f, 0.0f));
	m_SpringArm->TargetArmLength = 400.f;
	m_SpringArm->bEnableCameraLag = true;
	m_SpringArm->CameraLagSpeed = 3.0f;

	m_Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	m_Cam->SetupAttachment(m_SpringArm, USpringArmComponent::SocketName);

	//Take control of the default Player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

}

// Called when the game starts or when spawned
void AARTS_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARTS_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_Cam->FieldOfView = FMath::Lerp<float>(90.0f, 60.0f, 0.0f);
	m_SpringArm->TargetArmLength = FMath::Lerp<float>(400.0f, 300.0f, 0.0f);

	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += m_Camera.X;
		SetActorRotation(NewRotation);
	}

	//Rotate our camera's pitch, but limit it so we're always looking downward
	{
		FRotator NewRotation = m_SpringArm->GetComponentRotation();
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + m_Camera.Y, -80.0f, -15.0f);
		m_SpringArm->SetWorldRotation(NewRotation);
	}

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		FHitResult TraceHitResult;
		PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
		FVector CursorFV = TraceHitResult.ImpactNormal;
		FRotator CursorR = CursorFV.Rotation();
		CursorToWorld->SetWorldLocation(TraceHitResult.Location);
		CursorToWorld->SetWorldRotation(CursorR);
	}

	if (!m_Movement.IsZero())
	{
		//Scale our movement input axis values by 100 units per second
		m_Movement = m_Movement.SafeNormal() * 100.0f;
		FVector NewLocation = GetActorLocation();
		NewLocation += GetActorForwardVector() * m_Movement.X * DeltaTime;
		NewLocation += GetActorRightVector() * m_Movement.Y * DeltaTime;
		SetActorLocation(NewLocation);
	}

}

// Called to bind functionality to input
void AARTS_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// -------- RTS --------
void AARTS_Pawn::MoveToClick()
{

}

// ------ ACTION ------
void AARTS_Pawn::MoveForward(float _axisVal)
{
	m_Movement.X = FMath::Clamp<float>(_axisVal, -1.0f, 1.0f);
}

void AARTS_Pawn::MoveRight(float _axisVal)
{
	m_Movement.Y = FMath::Clamp<float>(_axisVal, -1.0f, 1.0f);
}


void AARTS_Pawn::CamPitch(float _axisVal)
{
	m_Camera.Y = _axisVal;
}


void AARTS_Pawn::CamYaw(float _axisVal)
{
	m_Camera.X = _axisVal;
}



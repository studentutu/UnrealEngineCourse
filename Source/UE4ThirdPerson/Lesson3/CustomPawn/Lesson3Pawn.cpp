// Fill out your copyright notice in the Description page of Project Settings.


#include "Lesson3Pawn.h"


// Sets default values
ALesson3Pawn::ALesson3Pawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMesh->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ALesson3Pawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALesson3Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ALesson3Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ZoomIn"), EInputEvent::IE_Pressed, this, &ALesson3Pawn::ZoomIn);
	PlayerInputComponent->BindAction(TEXT("ZoomOut"), EInputEvent::IE_Pressed, this, &ALesson3Pawn::ZoomOut);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ALesson3Pawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ALesson3Pawn::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ALesson3Pawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &ALesson3Pawn::LookRight);
}

void ALesson3Pawn::ZoomIn()
{
	float ZoomFieldOfViewStep = 2.5f;
	float ZoomLengthStep = 16.166f;

	Camera->FieldOfView = FMath::Clamp(Camera->FieldOfView - ZoomFieldOfViewStep, 75.0f, 90.0f);
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength - ZoomLengthStep, 200.0f, 300.0f);
}

void ALesson3Pawn::ZoomOut()
{
	float ZoomFieldOfViewStep = 2.5f;
	float ZoomLengthStep = 16.166f;

	Camera->FieldOfView = FMath::Clamp(Camera->FieldOfView + ZoomFieldOfViewStep, 75.0f, 90.0f);
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength + ZoomLengthStep, 200.0f, 300.0f);
}

void ALesson3Pawn::MoveForward(float Value)
{
	if (FMath::IsNearlyZero(Value))
	{
		return;
	}
	float DirectionLength = 100.0f;
	FVector ForwardDirection = GetActorForwardVector() * DirectionLength;

	AddActorWorldOffset(ForwardDirection * Value * GetWorld()->GetDeltaSeconds(), true);
}

void ALesson3Pawn::MoveRight(float Value)
{
	if (FMath::IsNearlyZero(Value))
	{
		return;
	}
	float DirectionLength = 100.0f;
	FVector RightDirection = GetActorRightVector() * DirectionLength;

	// SetActorLocation()  -- teleport - will not check collisions

	AddActorWorldOffset(RightDirection * Value * GetWorld()->GetDeltaSeconds(), true);
}

void ALesson3Pawn::LookUp(float Value)
{
	auto turnRate = 50.0f;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Blue, FString::Printf(TEXT("Pith %f"), Value));
	}

	AddControllerPitchInput(Value * turnRate * GetWorld()->GetDeltaSeconds());
}

void ALesson3Pawn::LookRight(float Value)
{
	auto turnRate = 50.0f;
	AddControllerYawInput(Value * turnRate * GetWorld()->GetDeltaSeconds());
}

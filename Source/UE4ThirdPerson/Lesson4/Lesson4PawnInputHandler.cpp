// Fill out your copyright notice in the Description page of Project Settings.


#include "Lesson4PawnInputHandler.h"


// Sets default values
ALesson4PawnInputHandler::ALesson4PawnInputHandler()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMesh->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ALesson4PawnInputHandler::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALesson4PawnInputHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ALesson4PawnInputHandler::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ScaleUp"), EInputEvent::IE_Pressed, this,
	                                 &ALesson4PawnInputHandler::ScaleUp);
	PlayerInputComponent->BindAction(TEXT("ScaleDown"), EInputEvent::IE_Pressed, this,
	                                 &ALesson4PawnInputHandler::ScaleDown);

	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this,
	                                 &ALesson4PawnInputHandler::Shoot);

	// Axis
	PlayerInputComponent->BindAxis(TEXT("ForceLookDown"), this, &ALesson4PawnInputHandler::ForceLookDown);
}

void ALesson4PawnInputHandler::ScaleUp()
{
	auto scale = StaticMesh->GetComponentTransform().GetScale3D().X;

	scale += 0.25f;
	scale = FMath::Clamp(scale, 0.5f, 2.0f);

	StaticMesh->SetWorldScale3D(FVector::OneVector * scale);
}

void ALesson4PawnInputHandler::ScaleDown()
{
	auto scale = StaticMesh->GetComponentTransform().GetScale3D().X;

	scale -= 0.25f;
	scale = FMath::Clamp(scale, 0.5f, 2.0f);

	StaticMesh->SetWorldScale3D(FVector::OneVector * scale);
}

void ALesson4PawnInputHandler::Shoot()
{
	auto getCurrentRotation = GetActorRotation().Quaternion();
	FRotator spawnRotation = getCurrentRotation.Rotator();
	FVector spawnLocation = GetActorLocation() + GetActorForwardVector() * 100;
	FActorSpawnParameters actorSpawnParameters;

	actorSpawnParameters.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;


	RefToLastBullet = GetWorld()->SpawnActor<ABullet>(ItemCLass, spawnLocation, spawnRotation, actorSpawnParameters);
}

void ALesson4PawnInputHandler::ForceLookDown(float value)
{
	if (FMath::IsNearlyZero(value))
	{
		return;
	}

	if (RefToLastBullet == nullptr)
	{
		return;
	}

	RefToLastBullet->RotatePitch(value);
}

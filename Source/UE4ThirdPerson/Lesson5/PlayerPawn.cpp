// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	// CapsuleComponent->SetCollisionProfileName(TEXT("123"));
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComponent->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	CapsuleComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	CapsuleComponent->SetCapsuleHalfHeight(90.0f);
	CapsuleComponent->SetCapsuleRadius(50.0f);

	CapsuleComponent->SetupAttachment(RootComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(CapsuleComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	// If secondary components attached to RootCOmponent -> they will not use the location of RootLocation - only hierarchycal moving
	SpringArmComponent->SetupAttachment(StaticMeshComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ZoomIn"), EInputEvent::IE_Pressed, this, &APlayerPawn::ZoomIn);
	PlayerInputComponent->BindAction(TEXT("ZoomOut"), EInputEvent::IE_Pressed, this, &APlayerPawn::ZoomOut);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerPawn::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerPawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APlayerPawn::LookRight);
}

void APlayerPawn::ZoomIn()
{
	float ZoomFieldOfViewStep = 2.5f;
	float ZoomLengthStep = 16.166f;

	CameraComponent->FieldOfView = FMath::Clamp(CameraComponent->FieldOfView - ZoomFieldOfViewStep, 75.0f, 90.0f);
	SpringArmComponent->TargetArmLength = FMath::Clamp(SpringArmComponent->TargetArmLength - ZoomLengthStep, 200.0f,
	                                                   300.0f);
}

void APlayerPawn::ZoomOut()
{
	float ZoomFieldOfViewStep = 2.5f;
	float ZoomLengthStep = 16.166f;

	CameraComponent->FieldOfView = FMath::Clamp(CameraComponent->FieldOfView + ZoomFieldOfViewStep, 75.0f, 90.0f);
	SpringArmComponent->TargetArmLength = FMath::Clamp(SpringArmComponent->TargetArmLength + ZoomLengthStep, 200.0f,
	                                                   300.0f);
}

void APlayerPawn::MoveForward(float Value)
{
	// if (GEngine)
	// {
	// 	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red,
	// 	                                 FString::Printf(TEXT("STart MOve Forward overlapping with %f"), Value), true,
	// 	                                 FVector2D(2.0f));
	// }
	if (Value != 0.0f)
	{
		float DirectionLength = 100.0f;
		FVector ForwardDirection = GetActorForwardVector() * DirectionLength;

		AddActorWorldOffset(ForwardDirection * Value * GetWorld()->GetDeltaSeconds(), false);
	}
}

void APlayerPawn::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// if (GEngine)
		// {
		// 	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red,
		// 	                                 FString::Printf(TEXT("STart MOve Right overlapping with %f"), Value), true,
		// 	                                 FVector2D(2.0f));
		// }
		float DirectionLength = 100.0f;
		FVector RightDirection = GetActorRightVector() * DirectionLength;

		AddActorWorldOffset(RightDirection * Value * GetWorld()->GetDeltaSeconds(), false);
	}
}

void APlayerPawn::LookUp(float Value)
{
	if (Value != 0.0f)
	{
		float TurnRate = 50.0f;
		AddControllerPitchInput(Value * TurnRate * GetWorld()->GetDeltaSeconds());
	}
}

void APlayerPawn::LookRight(float Value)
{
	if (Value != 0.0f)
	{
		float TurnRate = 50.0f;
		AddControllerYawInput(Value * TurnRate * GetWorld()->GetDeltaSeconds());
	}
}


void APlayerPawn::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                 const FHitResult& SweepResult)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red,
		                                 FString::Printf(TEXT("Begin overlapping with %s"), *OtherActor->GetName()),
		                                 true, FVector2D(2.0f));
	}
}

void APlayerPawn::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                               UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red,
		                                 FString::Printf(TEXT("End overlapping with %s"), *OtherActor->GetName()), true,
		                                 FVector2D(2.0f));
	}
}

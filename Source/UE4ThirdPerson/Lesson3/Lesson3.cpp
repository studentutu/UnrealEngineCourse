// Fill out your copyright notice in the Description page of Project Settings.


#include "Lesson3.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values
ALesson3::ALesson3()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ALesson3::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALesson3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALesson3::Spawn()
{
	if (ItemCLass == NULL)
	{
		return;
	}

	if (BoxComponent == nullptr)
	{
		return;
	}
	FRotator spawnRotation = FRotator();
	FVector spawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(
		BoxComponent->GetComponentLocation(), BoxComponent->GetScaledBoxExtent());
	FActorSpawnParameters actorSpawnParameters;

	actorSpawnParameters.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	// ESpawnActorCollisionHandlingMethod:: AdjustIfPossibleButDontSpawnIfColliding
	// ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn; - will spawn but find nearest free point or original point.

	

	GetWorld()->SpawnActor<AActor>(ItemCLass, spawnLocation, spawnRotation, actorSpawnParameters);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Lesson2Task1.h"


float ALesson2Task1::tempFLot;

// Sets default values
ALesson2Task1::ALesson2Task1()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create default mesh in BP
	MeshToSet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshToSet->SetupAttachment(RootComponent);

	// Create default collision in BP
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxComponent->SetupAttachment(MeshToSet);
}

// Called when the game starts or when spawned
void ALesson2Task1::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALesson2Task1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALesson2Task1::ChangeMesh(AActor* overlappedActor, UStaticMesh* newMesh)
{
	if (overlappedActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		MeshToSet->SetStaticMesh(newMesh);
	}
}

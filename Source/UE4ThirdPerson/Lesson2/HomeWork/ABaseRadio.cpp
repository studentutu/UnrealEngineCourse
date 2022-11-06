// Fill out your copyright notice in the Description page of Project Settings.


#include "ABaseRadio.h"

#include "Components/AudioComponent.h"


// Sets default values
AABaseRadio::AABaseRadio()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	SceneComponent->SetupAttachment(RootComponent);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(SceneComponent);

	Audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	Audio->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void AABaseRadio::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AABaseRadio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AABaseRadio::SetPaused(bool pause)
{
	Audio->SetPaused(pause);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlapPlayRadio.h"

#include "Components/AudioComponent.h"


// Sets default values
AOverlapPlayRadio::AOverlapPlayRadio()
	: Super()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxComponent->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void AOverlapPlayRadio::BeginPlay()
{
	Super::BeginPlay();
	Audio->Play();
	SetPaused(true);
}

void AOverlapPlayRadio::ActOnOverlap(AActor* overlappedActor, bool pause)
{
	if (overlappedActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		SetPaused(pause);
	}
}

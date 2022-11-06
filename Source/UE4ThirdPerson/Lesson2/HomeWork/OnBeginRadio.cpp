// Fill out your copyright notice in the Description page of Project Settings.


#include "OnBeginRadio.h"

#include "Components/AudioComponent.h"


AOnBeginRadio::AOnBeginRadio()
	: Super()
{
}

// Called when the game starts or when spawned
void AOnBeginRadio::BeginPlay()
{
	Super::BeginPlay();

	Audio->Play();
	SetPaused(false);
}

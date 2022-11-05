// Fill out your copyright notice in the Description page of Project Settings.


#include "HideActorAfterSeconds.h"


// Sets default values for this component's properties
UHideActorAfterSeconds::UHideActorAfterSeconds()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHideActorAfterSeconds::BeginPlay()
{
	Super::BeginPlay();

	// ...
	/* Activate the timer and stores it in a reference */
	auto& timerManager = GetWorld()->GetTimerManager();
	timerManager.SetTimer(timerReference,this,&UHideActorAfterSeconds::OnHidden, 5, false);
}


// Called every frame
void UHideActorAfterSeconds::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHideActorAfterSeconds::OnHidden()
{
	GetWorld()->GetTimerManager().ClearTimer(timerReference);

	StaticMeshReference->SetActorHiddenInGame(true);
}


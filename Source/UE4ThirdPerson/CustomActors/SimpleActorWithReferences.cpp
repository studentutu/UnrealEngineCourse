// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleActorWithReferences.h"


// Sets default values for this component's properties
USimpleActorWithReferences::USimpleActorWithReferences()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USimpleActorWithReferences::BeginPlay()
{
	Super::BeginPlay();

	// ...

	auto rendererOnScene = StaticMeshReference->GetStaticMeshComponent();
	materialCached = UMaterialInstanceDynamic::Create(rendererOnScene->GetMaterial(0), NULL);
	rendererOnScene->SetMaterial(0,materialCached);
	
	RunTimer();
}


// Called every frame
void USimpleActorWithReferences::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USimpleActorWithReferences::RunTimer()
{
	/* Activate the timer and stores it in a reference */
	auto& timerManager = GetWorld()->GetTimerManager();
	timerManager.SetTimer(timerReference,this,&USimpleActorWithReferences::OnTimerUpdated, TimerInSeconds, false);
}

void USimpleActorWithReferences::OnTimerUpdated()
{
	IsInAColor = !IsInAColor;

	// auto colorToUse = FVector4(0,0,1,1);
	// if(IsInAColor)
	// {
	// 	colorToUse = FVector4(1,0,0,1);
	// }

	auto colorToUse = IsInAColor? ColorA:  ColorB;
	
	materialCached->SetVectorParameterValue( TEXT("Color"),static_cast<FLinearColor>(colorToUse) );
	RunTimer();
}


 


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/StaticMeshActor.h"
#include "SimpleActorWithReferences.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UE4THIRDPERSON_API USimpleActorWithReferences : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimerInSeconds;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	AStaticMeshActor* StaticMeshReference;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FColor ColorA;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FColor ColorB;
	
	// Sets default values for this component's properties
	USimpleActorWithReferences();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	/* Handle to manage the timer */
	FTimerHandle timerReference;

	// material to be used
	UMaterialInstanceDynamic* materialCached = nullptr;

	bool IsInAColor = false;

	void RunTimer();

	void OnTimerUpdated();
};

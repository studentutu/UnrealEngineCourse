// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ABaseRadio.h"
#include "Components/BoxComponent.h"
#include "OverlapPlayRadio.generated.h"

UCLASS()
class UE4THIRDPERSON_API AOverlapPlayRadio : public AABaseRadio
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBoxComponent* BoxComponent;
	
	AOverlapPlayRadio();
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ActOnOverlap(AActor* overlappedActor, bool pause);
};

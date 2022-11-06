// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ABaseRadio.h"
#include "Components/BoxComponent.h"
#include "OnBeginRadio.generated.h"

/**
 * 
 */
UCLASS()
class UE4THIRDPERSON_API AOnBeginRadio : public AABaseRadio
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBoxComponent* BoxComponent;
	
	AOnBeginRadio();
	
	virtual void BeginPlay() override;
	
};

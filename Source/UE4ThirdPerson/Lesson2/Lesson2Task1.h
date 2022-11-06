// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Lesson2Task1.generated.h"


/**
 * @brief
 * Hybrid approach - cpp checks but get references from BP.
 */
UCLASS()
class UE4THIRDPERSON_API ALesson2Task1 : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* MeshToSet;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBoxComponent* BoxComponent;


	// Sets default values for this actor's properties
	ALesson2Task1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	static float tempFLot;
	UFUNCTION(BlueprintCallable)
	void ChangeMesh(AActor* overlappedActor, UStaticMesh* newMesh);
};

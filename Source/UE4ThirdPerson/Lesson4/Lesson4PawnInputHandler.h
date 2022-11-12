// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "UECourse/Bullets/Bullet.h"
#include "Lesson4PawnInputHandler.generated.h"

UCLASS()
class UECOURSE_API ALesson4PawnInputHandler : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCameraComponent* Camera;

	// Sets default values for this pawn's properties
	ALesson4PawnInputHandler();

protected:
	ABullet* RefToLastBullet;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<class AActor> ItemCLass;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ScaleUp();

	void ScaleDown();

	void Shoot();
	void ForceLookDown(float value);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"


// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForward();
}

void ABullet::MoveForward()
{
	float speed = 250.0f;

	FVector Direction = GetActorForwardVector() * speed;
	AddActorWorldOffset(Direction * GetWorld()->GetDeltaSeconds(), true);
}

void ABullet::RotatePitch(float value)
{
	auto angle = value * 30 * GetWorld()->GetDeltaSeconds();
	auto rotationEuler = GetActorRotation().Quaternion().Euler();

	SetActorRotation(FRotator(rotationEuler.X + angle, rotationEuler.Y, rotationEuler.Z));
}

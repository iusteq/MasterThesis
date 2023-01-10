// Fill out your copyright notice in the Description page of Project Settings.


#include "LogMoving.h"

// Sets default values
ALogMoving::ALogMoving()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALogMoving::BeginPlay()
{
	Super::BeginPlay();
	startingPoint = GetActorLocation();

}

// Called every frame
void ALogMoving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTheLog(DeltaTime);
}

void ALogMoving::MoveTheLog(float DeltaTime)
{
	if (IsDistanceMax())
	{
		FVector directionOfMovement = logVelocity.GetSafeNormal();
		startingPoint += directionOfMovement * distanceToMove;
		SetActorLocation(startingPoint);
		logVelocity = -logVelocity;
	}
	else {
		FVector current = GetActorLocation();
		current += logVelocity * DeltaTime;
		SetActorLocation(current);
	}
}

float ALogMoving::GetDistanceMoved() const
{
	float distance = FVector::Dist(startingPoint, GetActorLocation());
	return distance;
}

bool ALogMoving::IsDistanceMax() const
{
	return GetDistanceMoved() > distanceToMove;
}



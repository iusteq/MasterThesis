// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LogMoving.generated.h"

UCLASS()
class BUCOVINA_API ALogMoving : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ALogMoving();

protected:
	
	virtual void BeginPlay() override;

public:	
		virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector logVelocity = FVector(0, 0, 80);

	UPROPERTY(EditAnywhere, Category = "Movement")
		float distanceToMove = 100;

	FVector startingPoint;

	void MoveTheLog(float DeltaTime);
	bool IsDistanceMax() const;
	float GetDistanceMoved() const;

};

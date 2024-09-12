// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(EditAnyWhere, Category = "Moving")
	FVector PlatformVelocity = FVector(100.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnyWhere, Category = "Moving")
	float MoveDistance = 3000;
	UPROPERTY(EditAnyWhere, Category = "Rotation")
	FRotator RotationVelocity;
	
	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn();

	float GetDistanceMoved();
};

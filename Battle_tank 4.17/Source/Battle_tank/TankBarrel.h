// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 c'est descendre, et +1 c'est monter
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10;//sensible default
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesElevation = 40;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinDegreesElevation = 0;
	
	
};

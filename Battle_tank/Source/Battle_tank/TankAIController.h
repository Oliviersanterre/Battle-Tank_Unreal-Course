// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;

private:

	APawn* ControlledTank = nullptr;
	APawn* PlayerTank = nullptr;
	
};

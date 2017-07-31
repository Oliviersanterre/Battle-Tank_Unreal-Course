// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	

	Tank = GetControlledTank();
	
}

void ATankPlayerController::Tick (float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardCrosshair();


}


ATank* ATankPlayerController::GetControlledTank() const
{
	
	
	return Cast<ATank>(GetPawn());
	
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!Tank) { return; }
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("This is hit location : %s"), *HitLocation.ToString());
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}



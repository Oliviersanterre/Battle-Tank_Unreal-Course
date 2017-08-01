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
		UE_LOG(LogTemp, Warning, TEXT("hit location : %s"), *HitLocation.ToString());
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = { ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation };
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & WorldDirection) const
{
	FVector WorldLocation; //To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation[0], ScreenLocation[1], WorldLocation, WorldDirection);
	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto LineTraceEnd = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, LineTraceEnd, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;

}




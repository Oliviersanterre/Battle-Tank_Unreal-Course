// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller works"));
	

	Tank = GetControlledTank();
	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player got control of : %s"), *Tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Get Controlled tank didn't work"));
	}
}


ATank* ATankPlayerController::GetControlledTank() const
{
	
	
	return Cast<ATank>(GetPawn());
	
}



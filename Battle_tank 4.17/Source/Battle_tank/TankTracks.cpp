// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"


void UTankTracks::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); // le Owner c'est l'objet blueprint, pis le root component c'est le tank. Le cast ca sert a donner le bon genre d'objet
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


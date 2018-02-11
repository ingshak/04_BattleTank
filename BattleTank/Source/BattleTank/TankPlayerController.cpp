// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Unable to received Controlled Tank %s"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank Received %s"), *(ControlledTank->GetName()))
	}
		
}

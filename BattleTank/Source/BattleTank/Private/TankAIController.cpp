// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AIControlledTank = GetControlledTank();
	if (!AIControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Unable to received AI Controlled Tank %s"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank Received %s"), *(AIControlledTank->GetName()))
	}

}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

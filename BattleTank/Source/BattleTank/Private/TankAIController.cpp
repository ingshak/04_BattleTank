// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AIControlledTank = GetPlayerTank();
	if (!AIControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Unable to received AI Controlled Tank"));
	}
	else {
		auto actorCount = GetWorld()->GetActorCount();
		//auto actorCountInString = std::to_string(actorCount);
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank Received %s"), *(AIControlledTank->GetName()));
	}

}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	
}
 

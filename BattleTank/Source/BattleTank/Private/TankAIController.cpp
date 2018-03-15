// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

//Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	//auto ControlledTank = Cast<ATank>(GetPawn());
	auto aimComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(PlayerTank)) {
		MoveToActor(PlayerTank, AcceptanceRadius);
		aimComponent->AimAt(PlayerTank->GetActorLocation());
		//BControlledTank->Fire();
	}

}
 

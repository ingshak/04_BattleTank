// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
//#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"


/*ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}*/

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	/*auto ControlledTank = GetPawn();
	if (!ensure(ControlledTank)) {
		return;
	}*/
	 
	auto aimComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(aimComponent)) {
		FoundAimingComponent(aimComponent);
	} 
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	auto aimComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(aimComponent)) {
		return;
	}

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		aimComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(OUT FVector& HitLocation) const {
	int32 ViewportSizeX, ViewportSizeY;
	//Find the crosshair position in pixel coordinates.
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector WorldLocation; //To be discarded

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)) {
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}


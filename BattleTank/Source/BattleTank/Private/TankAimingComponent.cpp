// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;  

	// ...
}


void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel && Turret))
		return;

	//if (!Turret) {
	//	UE_LOG(LogTemp, Warning, TEXT("INVALID TURRET from "))
	//		return;
	//}
		
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool  bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);
	if(bHaveAimSolution){

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto BarrelLocation = Barrel->GetComponentLocation().ToString();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s at %s"), *GetOwner()->GetName(), *HitLocation.ToString(), *BarrelLocation, *OutLaunchVelocity.ToString())
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	if (!ensure(Barrel && Turret))
		return;
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"),*AimAsRotator.ToString())
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}


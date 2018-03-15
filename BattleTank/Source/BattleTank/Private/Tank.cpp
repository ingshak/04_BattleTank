// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
//#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Engine/World.h"
#include "Projectile.h"
// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("DONKEY: Tank C++ Construct %s "), *GetName())
		//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
		//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
}

void ATank::BeginPlay() {
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("DONKEY: Tank C++ Begin Play %s "), *GetName())
	//TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}
//void ATank::AimAt(FVector HitLocation) {
//	if (!ensure(TankAimingComponent))
//		return;
//	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
//}

void ATank::Fire()
{
	if (!ensure(Barrel))
		return;
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (!isReloaded)
		return;

	//GetWorld()->SpawnActor<AProjectile>();
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);

	//Projectile->LaunchProjectile(LaunchSpeed);
	LastFireTime = FPlatformTime::Seconds();
}

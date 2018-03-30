// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	UFUNCTION(BlueprintCallable, Category = Input)
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	void AimAt(FVector WorldSpaceAim);
	UPROPERTY(BlueprintReadonly, Category = "State")
		EFiringState FiringState = EFiringState::Reloading;
	UFUNCTION(BlueprintCallable)
		void Fire();
	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable)
	int GetRoundsLeft() const;

private:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	virtual void BeginPlay() override;
	void MoveBarrelTowards(FVector AimDirection); 
	bool IsBarrelMoving();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint; //Alternative to UClass*

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float ReloadTimeInSeconds = 3;

	FVector AimDirection;

	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	int RoundsLeft = 3;
};

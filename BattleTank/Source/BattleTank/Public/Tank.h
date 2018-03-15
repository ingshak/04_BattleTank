// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "TankAimingComponent.h"
#include "Tank.generated.h" //Add includes above this line
//forward declarations
//class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	

	UFUNCTION(BlueprintCallable)
		void Fire();

protected:
	
	//UPROPERTY(BlueprintReadonly)
	//UTankAimingComponent* TankAimingComponent = nullptr;
	
	void BeginPlay() override;
private:

	

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint; //Alternative to UClass*

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float ReloadTimeInSeconds = 3;
	 
	UTankBarrel* Barrel = nullptr;
	double LastFireTime = 0;
};

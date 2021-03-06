// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"//Must be the last include

//class ATank;
/**
 * 
 */
class UTankAimingComponent;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	//UFUNCTION(BlueprintCallable, Category = "Setup")
		//ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);



private:
	
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


	//Start the tank moving the barrel so that the a shot would hit where 
	// the crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(OUT FVector& Vector) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.;
};

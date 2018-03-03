// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (!LeftTrack) {
		UE_LOG(LogTemp, Warning, TEXT("Left Track not set"));
		return;
	}
	if (!RightTrack) {
		UE_LOG(LogTemp, Warning, TEXT("Rigth Track not set"));
		return;
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

}

void UTankMovementComponent::IntendTurnRight(float Throw) {
	if (!LeftTrack) {
		UE_LOG(LogTemp, Warning, TEXT("Left Track not set"));
		return;
	}
	if (!RightTrack) {
		UE_LOG(LogTemp, Warning, TEXT("Rigth Track not set"));
		return;
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

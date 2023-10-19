// Fill out your copyright notice in the Description page of Project Settings.


#include "COMShakeItem.h"

// Sets default values for this component's properties
UCOMShakeItem::UCOMShakeItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	isRunning = false;
	runTimer = 0;
	runDuration = 1;
	shakeOffset = 3;
}


// Called when the game starts
void UCOMShakeItem::BeginPlay()
{
	Super::BeginPlay();
	originalLocation = GetOwner()->GetActorLocation();
	
}

// Called every frame
void UCOMShakeItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (isRunning) {
		runTimer += DeltaTime;
		AActor* Parent = GetOwner();
		FVector currentLocation = originalLocation;

		if (runTimer < runDuration) {
			//UE_LOG(LogTemp, Warning, TEXT("MOVING THING"));
			if (Parent) {
				float xOffset = rand() % static_cast<int>(shakeOffset * 2) - shakeOffset;
				currentLocation.X = originalLocation.X + xOffset;
				/*float yOffset = rand() % static_cast<int>(5 * 2) - 5;
				currentLocation.Y = originalLocation.Y + yOffset;*/

				Parent->SetActorLocation(currentLocation);
			}
		} else {
			// stop and put us back where we started
			runTimer = 0;
			isRunning = false;
			UE_LOG(LogTemp, Warning, TEXT("DONE SHAKING"));
			Parent->SetActorLocation(originalLocation);
		}

	}
}

void UCOMShakeItem::Run()
{
	UE_LOG(LogTemp, Warning, TEXT("Running Shake Component"));
	isRunning = true;
}

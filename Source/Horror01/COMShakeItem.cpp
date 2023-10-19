// Fill out your copyright notice in the Description page of Project Settings.


#include "COMShakeItem.h"

// Sets default values for this component's properties
UCOMShakeItem::UCOMShakeItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	isRunning = false;

	// ...
}


// Called when the game starts
void UCOMShakeItem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Run();
	
}


// Called every frame
void UCOMShakeItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (isRunning) {
		AActor* Parent = GetOwner();
		UE_LOG(LogTemp, Warning, TEXT("MOVING THING"));
		if (Parent) {
			Parent->SetActorLocation(
				Parent->GetActorLocation() + FVector(44, 44, 44)
			);
		}
		isRunning = false;
	}
}

void UCOMShakeItem::Run()
{
	UE_LOG(LogTemp, Warning, TEXT("Running Shake Component"));
	isRunning = true;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "COMShakeItem.h"

// Sets default values for this component's properties
UCOMShakeItem::UCOMShakeItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCOMShakeItem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	isRunning = false;
	Run();
	
}


// Called every frame
void UCOMShakeItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCOMShakeItem::Run()
{
	UE_LOG(LogTemp, Warning, TEXT("Running Shake Component"));
}


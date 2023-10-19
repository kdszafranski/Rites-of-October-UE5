// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "COMShakeItem.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HORROR01_API UCOMShakeItem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOMShakeItem();

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	float runTimer;
	FVector originalLocation;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category="Component Settings")
	bool isRunning;
	UPROPERTY(EditAnywhere, Category="Component Settings")
	float runDuration;
	UPROPERTY(EditAnywhere, Category = "Component Settings")
	float shakeOffset;
	
	// Starts our animation
	UFUNCTION(BlueprintCallable)
	void Run();
		
};

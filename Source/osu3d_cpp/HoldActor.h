// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "HoldActor.generated.h"

UCLASS()
class OSU3D_CPP_API AHoldActor : public AActor
{
	GENERATED_BODY()
private:
	int lastTime;
	int liveTime;
	bool spawned;
	AHoldActor *moveActor;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterial * videoPlayerMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 hitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 endTime;

	// Sets default values for this actor's properties
	AHoldActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "HoldActor")
		void SetLastTime(int32 value);
	
	UFUNCTION(BlueprintCallable, Category = "HoldActor")
		void SetHitTime(int32 t);

	UFUNCTION(BlueprintCallable, Category = "HoldActor")
		void SetEndTime(int32 t);

	void SetSpawned(bool);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SongMap.h"
#include "ArrowActor.generated.h"

UCLASS()
class OSU3D_CPP_API AArrowActor : public AActor
{
	GENERATED_BODY()
private:
	int liveTime;
	bool spawned;
	AArrowActor *moveActor;


public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterial * videoPlayerMaterial;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 hitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UNodeDirection direction;

	// Sets default values for this actor's properties
	AArrowActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void SetSpawned(bool);

	UFUNCTION(BlueprintCallable, Category = "HoldActor")
		void SetHitTime(int32 t);

	UFUNCTION(BlueprintCallable, Category = "HoldActor")
		void SetDirection(UNodeDirection dir);
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "OnScreenBuffer.generated.h"

UCLASS()
class OSU3D_CPP_API AOnScreenBuffer : public AActor
{
	GENERATED_BODY()

	TQueue<AActor*> buffer;
	int32 count;
	
public:	
	// Sets default values for this actor's properties
	AOnScreenBuffer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "Buffer")
		AActor *Dequeue();

	UFUNCTION(BlueprintCallable, Category = "Buffer")
		void Enqueue(AActor *node);

	UFUNCTION(BlueprintCallable, Category = "Buffer")
		AActor *Peek();

	UFUNCTION(BlueprintCallable, Category = "Buffer")
		int32 Size() const;

	UFUNCTION(BlueprintCallable, Category = "Buffer")
		void Clear();
	
};

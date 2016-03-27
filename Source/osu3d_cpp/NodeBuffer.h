// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SongMap.h"
#include "NodeBuffer.generated.h"

UCLASS()
class OSU3D_CPP_API ANodeBuffer : public AActor
{
	GENERATED_BODY()

private:
	TQueue<UBeatNode*> buffer;
	int32 count;
	
public:	
	// Sets default values for this actor's properties
	ANodeBuffer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "Buffer")
	UBeatNode *Dequeue();
	
	UFUNCTION(BlueprintCallable, Category = "Buffer")
	void Enqueue(UBeatNode *node);

	UFUNCTION(BlueprintCallable, Category = "Buffer")
	UBeatNode *Peek();

	UFUNCTION(BlueprintCallable, Category = "Buffer")
	int32 Size() const;

	UFUNCTION(BlueprintCallable, Category = "Buffer")
	void Clear();
};

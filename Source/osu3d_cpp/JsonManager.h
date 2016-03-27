// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SongMap.h"
#include "JsonManager.generated.h"

UCLASS()
class OSU3D_CPP_API AJsonManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJsonManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// ProcessJson
	UFUNCTION(BlueprintCallable, Category = "Json")
	USongMap *ProcessJson(const FString content);

	UFUNCTION(BlueprintCallable, Category = "Json")
	TArray<FString> ProcessSongList(const FString content);
};

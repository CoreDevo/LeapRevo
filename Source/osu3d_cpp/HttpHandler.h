// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Http.h"
#include "HttpHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJsonReady, FString, content);

UCLASS()
class OSU3D_CPP_API AHttpHandler : public AActor
{
	GENERATED_BODY()

private:
	static const FString SongListURL;
	static const FString MapURL;
	static const FString ScoreURL;
	
public:	

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category ="http")
	TArray<FString> arraystring;

	UPROPERTY(BlueprintAssignable, Category = "Json")
	FJsonReady jsonReady;
	UPROPERTY(BlueprintAssignable, Category = "Json")
	FJsonReady listReady;
	// Sets default values for this actor's properties
	AHttpHandler();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "http")
	void RequestMap(const FString & mapName);
	UFUNCTION(BlueprintCallable, Category = "http")
	void RequestSongList();
	UFUNCTION(BlueprintCallable, Category = "http")
	void SendScore(const FString &name, int32 s);

	void OnRequestMapSuccess(FHttpRequestPtr, FHttpResponsePtr, bool);
	void OnRequestSongListSuccess(FHttpRequestPtr, FHttpResponsePtr, bool);
	void OnSendScoreSuccess(FHttpRequestPtr, FHttpResponsePtr, bool);

	
};

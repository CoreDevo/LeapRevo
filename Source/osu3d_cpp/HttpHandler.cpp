// Fill out your copyright notice in the Description page of Project Settings.

#include "osu3d_cpp.h"
#include "HttpHandler.h"


// Sets default values
AHttpHandler::AHttpHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

const FString AHttpHandler::SongListURL = "http://ec2-54-152-143-50.compute-1.amazonaws.com:9012/songlist";
const FString AHttpHandler::MapURL = "http://ec2-54-152-143-50.compute-1.amazonaws.com:9015/songs";
const FString AHttpHandler::ScoreURL = "http://ec2-54-152-143-50.compute-1.amazonaws.com:12099/uploadscore";

// Called when the game starts or when spawned
void AHttpHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHttpHandler::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AHttpHandler::RequestMap(const FString &mapName) {
	FString fullURL = MapURL + "/" + mapName + "/map.json";

	TSharedRef<IHttpRequest> httpRequest = FHttpModule::Get().CreateRequest();
	httpRequest->SetVerb("GET");
	httpRequest->SetURL(fullURL);
	httpRequest->SetHeader(TEXT("Content-Type"), TEXT("text/plain"));

	httpRequest->OnProcessRequestComplete().BindUObject(this, &AHttpHandler::OnRequestMapSuccess);

	httpRequest->ProcessRequest();

}

void AHttpHandler::RequestSongList() {
	TSharedRef<IHttpRequest> httpRequest = FHttpModule::Get().CreateRequest();
	httpRequest->SetVerb("GET");
	httpRequest->SetURL(SongListURL);
	httpRequest->SetHeader(TEXT("Content-Type"), TEXT("text/plain"));

	httpRequest->OnProcessRequestComplete().BindUObject(this, &AHttpHandler::OnRequestSongListSuccess);

	httpRequest->ProcessRequest();
}

void AHttpHandler::SendScore(const FString &name, int32 s) {
	TSharedRef<IHttpRequest> httpRequest = FHttpModule::Get().CreateRequest();
	httpRequest->SetVerb("POST");
	httpRequest->SetURL(ScoreURL);
	httpRequest->SetHeader(TEXT("songname"), name);
	httpRequest->SetHeader(TEXT("score"), FString::FromInt(s));
	httpRequest->SetHeader(TEXT("time"), FString::SanitizeFloat(FPlatformTime::Seconds()));

	httpRequest->OnProcessRequestComplete().BindUObject(this, &AHttpHandler::OnSendScoreSuccess);


	httpRequest->ProcessRequest();
}

void AHttpHandler::OnRequestMapSuccess(FHttpRequestPtr request, FHttpResponsePtr response, bool success) {
	if (success)
	{
		uint32_t responseCode = response->GetResponseCode();
		UE_LOG(LogTemp, Warning, TEXT("Response Code: %d\n"), responseCode);
		FString responseData = response->GetContentAsString();
		UE_LOG(LogTemp, Warning, TEXT("Response: %s:\n"), *responseData);
		jsonReady.Broadcast(responseData);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Http was not successful\n"));
	}

}

void AHttpHandler::OnRequestSongListSuccess(FHttpRequestPtr request, FHttpResponsePtr response, bool success) {
	if (success)
	{
		uint32_t responseCode = response->GetResponseCode();
		UE_LOG(LogTemp, Warning, TEXT("Response Code: %d\n"), responseCode);
		FString responseData = response->GetContentAsString();
		UE_LOG(LogTemp, Warning, TEXT("Response: %s\n"), *responseData);
		responseData.ParseIntoArrayLines(arraystring, false);
		UE_LOG(LogTemp, Warning, TEXT("Total songs: %d\n"), arraystring.Num());

		listReady.Broadcast(responseData);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Http was not successful\n"));
	}
}

void AHttpHandler::OnSendScoreSuccess(FHttpRequestPtr request, FHttpResponsePtr response, bool success) {
	if (success)
	{
		uint32_t responseCode = response->GetResponseCode();
		UE_LOG(LogTemp, Warning, TEXT("Response Code: %d\n"), responseCode);
		FString responseData = response->GetContentAsString();
		UE_LOG(LogTemp, Warning, TEXT("Response: %s:\n"), *responseData);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Http was not successful\n"));
	}

}
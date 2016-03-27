// Fill out your copyright notice in the Description page of Project Settings.

#include "osu3d_cpp.h"
#include "JsonManager.h"


// Sets default values
AJsonManager::AJsonManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AJsonManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJsonManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

USongMap *AJsonManager::ProcessJson(const FString content) {
	UE_LOG(LogTemp, Warning, TEXT("Start Deserialize Json\n"));
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);
	USongMap *result = nullptr;
	if (FJsonSerializer::Deserialize(Reader, JsonObject)) {
		result = NewObject<USongMap>();
		FString title;
		if (JsonObject->TryGetStringField("TitleUnicode", title)) {
			result->setTitle(title);
		}
		UE_LOG(LogTemp, Warning, TEXT("Get Title: %s \n"), *title);
		FString audioFile;
		if (JsonObject->TryGetStringField("AudioFilename", audioFile)) {
			result->setAuthor(audioFile);
		}
		UE_LOG(LogTemp, Warning, TEXT("Get AudioFile: %s \n"), *audioFile);
		const TArray<TSharedPtr<FJsonValue>> nodes = JsonObject->GetArrayField("hitObjects");
		for (int i = 0; i < nodes.Num(); i++)
		{
			const TSharedPtr<FJsonObject> nodeObject = nodes[i]->AsObject();
			int time = nodeObject->GetIntegerField("startTime");
			const TArray<TSharedPtr<FJsonValue>> point = nodeObject->GetArrayField("position");
			int x, y;
			FIntPoint position;
			if (point[0]->TryGetNumber(x) && point[1]->TryGetNumber(y)) {
				position.X = x;
				position.Y = y;
			}
			FString type = nodeObject->GetStringField("objectName");
			if (type == "up") {
				USingleNode *circle = NewObject<USingleNode>();
				circle->startTime = time;
				circle->startPosition = position;
				circle->direction = UNodeDirection::Up;
				circle->type = UNodeType::TypeSingleNode;
				result->addNode(circle);
			}
			else if (type == "down") {
				USingleNode *circle = NewObject<USingleNode>();
				circle->startTime = time;
				circle->startPosition = position;
				circle->direction = UNodeDirection::Down;
				circle->type = UNodeType::TypeSingleNode;
				result->addNode(circle);
			}
			else if (type == "left") {
				USingleNode *circle = NewObject<USingleNode>();
				circle->startTime = time;
				circle->startPosition = position;
				circle->direction = UNodeDirection::Left;
				circle->type = UNodeType::TypeSingleNode;
				result->addNode(circle);
			}
			else if (type == "right") {
				USingleNode *circle = NewObject<USingleNode>();
				circle->startTime = time;
				circle->startPosition = position;
				circle->direction = UNodeDirection::Right;
				circle->type = UNodeType::TypeSingleNode;
				result->addNode(circle);
			}
			else if (type == "hold") {
				int endTime = nodeObject->GetIntegerField("endTime");
				UBeatSlider *slider = NewObject<UBeatSlider>();
				slider->startTime = time;
				slider->endTime = endTime;
				slider->startPosition = position;
				slider->type = UNodeType::TypeSlider;
				result->addNode(slider);
			}
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Deserialize Json Failed\n"));
	}
	return result;
}

TArray<FString> AJsonManager::ProcessSongList(const FString content) {
	return TArray<FString>();
}
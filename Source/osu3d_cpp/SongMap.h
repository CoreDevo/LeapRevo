// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SongMap.generated.h"

UENUM(BlueprintType)
enum class UNodeType:uint8 {
	TypeSingleNode,
	TypeSlider,
	TypeSpinner
};

UENUM(BlueprintType)
enum class UNodeDirection :uint8 {
	Left,
	Right,
	Up,
	Down
};

UCLASS(BlueprintType)
class UBeatNode : public UObject {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "NodeProperty")
		int32 startTime;
	UPROPERTY(BlueprintReadOnly, Category = "NodeProperty")
		UNodeType type;
	UPROPERTY(BlueprintReadOnly, Category = "NodeProperty")
		FIntPoint startPosition;
	UBeatNode();
	UBeatNode(int32, UNodeType, FIntPoint);

};

UCLASS(BlueprintType)
class USingleNode : public UBeatNode {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "NodeProperty")
	UNodeDirection direction;
	USingleNode();

	USingleNode(int32, FIntPoint, UNodeDirection);

};

UCLASS(BlueprintType)
class UBeatSlider : public UBeatNode {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "NodeProperty")
	int32 endTime;
	UBeatSlider();

	UBeatSlider(int32, int32, FIntPoint);

};




UCLASS(BlueprintType)
class OSU3D_CPP_API USongMap : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
		TArray<UBeatNode*> beatNodes;
	UPROPERTY()
		FString title; 
	UPROPERTY()
		FString author;
	UPROPERTY()
		FString audioFile;

public:	
	// Sets default values for this actor's properties
	USongMap();

	UFUNCTION(BlueprintCallable, Category = "Getter")
	TArray<UBeatNode*> &getNodes();

	UFUNCTION(BlueprintCallable, Category = "Getter")
	FString &getTitle();

	UFUNCTION(BlueprintCallable, Category = "Getter")
	FString &getAuthor();

	UFUNCTION(BlueprintCallable, Category = "Getter")
	FString &getAudioFile();

	void addNode(UBeatNode *);
	void setTitle(const FString &);
	void setAuthor(const FString &);
	void setAudioFile(const FString &);
	
};

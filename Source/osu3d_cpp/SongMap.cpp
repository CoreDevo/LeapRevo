// Fill out your copyright notice in the Description page of Project Settings.

#include "osu3d_cpp.h"
#include "SongMap.h"

UBeatNode::UBeatNode() {}
UBeatNode::UBeatNode(int time, UNodeType type, FIntPoint point){
	startTime = time;
	this->type = type;
	startPosition = point;

}

USingleNode::USingleNode() {}

USingleNode::USingleNode(int time, FIntPoint point, UNodeDirection dir){
	direction = dir;
	startTime = time;
	this->type = UNodeType::TypeSingleNode;
	startPosition = point;
}

UBeatSlider::UBeatSlider() {}

UBeatSlider::UBeatSlider(int stime, int etime, FIntPoint point){
	startTime = stime;
	endTime = etime;
	this->type = UNodeType::TypeSlider;
	startPosition = point;
}


// Sets default values
USongMap::USongMap()
{
	title = "";
	author = "";
	audioFile = "";
}

TArray<UBeatNode*> &USongMap::getNodes() {
	return beatNodes;
}

FString &USongMap::getTitle() {
	return title;
}

FString &USongMap::getAuthor() {
	return author;
}

FString &USongMap::getAudioFile() {
	return audioFile;
}

void USongMap::addNode(UBeatNode *node) {
	beatNodes.Add(node);
}

void USongMap::setTitle(const FString &t) {
	title = t;
}

void USongMap::setAuthor(const FString &t) {
	author = t;
}

void USongMap::setAudioFile(const FString &t) {
	audioFile = t;
}


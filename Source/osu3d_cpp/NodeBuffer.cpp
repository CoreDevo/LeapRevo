// Fill out your copyright notice in the Description page of Project Settings.

#include "osu3d_cpp.h"
#include "NodeBuffer.h"


// Sets default values
ANodeBuffer::ANodeBuffer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	count = 0;
}

// Called when the game starts or when spawned
void ANodeBuffer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANodeBuffer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

UBeatNode *ANodeBuffer::Dequeue() {
	UBeatNode *node;
	if (buffer.Dequeue(node)) {
		count--;
		return node;
	}
	else
		return nullptr;
}

void ANodeBuffer::Enqueue(UBeatNode *node) {
	if (buffer.Enqueue(node)) count++;
}

UBeatNode *ANodeBuffer::Peek() {
	UBeatNode *top;
	if (buffer.Peek(top))
		return top;
	else
		return nullptr;
}

int32 ANodeBuffer::Size() const {
	return count;
}

void ANodeBuffer::Clear() {
	while (!buffer.IsEmpty()) {
		UBeatNode *node;
		buffer.Dequeue(node);
	}
}
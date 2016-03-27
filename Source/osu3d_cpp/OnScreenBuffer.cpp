// Fill out your copyright notice in the Description page of Project Settings.

#include "osu3d_cpp.h"
#include "OnScreenBuffer.h"


// Sets default values
AOnScreenBuffer::AOnScreenBuffer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AOnScreenBuffer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOnScreenBuffer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

AActor *AOnScreenBuffer::Dequeue() {
	AActor *node;
	if (buffer.Dequeue(node)) {
		count--;
		return node;
	}
	else
		return nullptr;
}

void AOnScreenBuffer::Enqueue(AActor *node) {
	if (buffer.Enqueue(node)) count++;
}

AActor *AOnScreenBuffer::Peek() {
	AActor *top;
	if (buffer.Peek(top))
		return top;
	else
		return nullptr;
}

int32 AOnScreenBuffer::Size() const {
	return count;
}

void AOnScreenBuffer::Clear() {
	while (!buffer.IsEmpty()) {
		AActor *node;
		buffer.Dequeue(node);
	}
}
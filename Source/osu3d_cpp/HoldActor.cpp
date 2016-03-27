// Fill out your copyright notice in the Description page of Project Settings.

#include "osu3d_cpp.h"
#include "HoldActor.h"


// Sets default values
AHoldActor::AHoldActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	lastTime = 0;
	liveTime = 1800;
	
	
}

// Called when the game starts or when spawned
void AHoldActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHoldActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	liveTime -= (int)(DeltaTime * 1000);
	if (liveTime < lastTime + 1450 && !spawned) {
		spawned = true;
		FTransform transform = ActorToWorld();
		FTransform offset;
		offset.SetScale3D(FVector(0, 0, 0));
		transform.Accumulate(offset);
		moveActor = GetWorld()->SpawnActor<AHoldActor>(GetClass(), transform);

		TArray<UStaticMeshComponent *> mesh;
		moveActor->GetComponents<UStaticMeshComponent>(mesh);
		UE_LOG(LogTemp, Warning, TEXT("Found Static Mesh: %d\n"), mesh.Num());

		mesh[0]->SetMaterial(0, videoPlayerMaterial);

		moveActor->SetSpawned(true);
	}

	if (liveTime < 0) {
		SetActorHiddenInGame(true);
		Destroy();
	}
	else if (liveTime < lastTime && moveActor) {
		moveActor->SetActorTransform(ActorToWorld());
	}
	else if (liveTime < lastTime + 1450 && moveActor) {
		FTransform transform = ActorToWorld();
		FTransform offset;
		float scale = 1.0 - (float)(liveTime - lastTime) / 1450;
		offset.SetScale3D(FVector(scale, scale, scale));
		transform.Accumulate(offset);
		moveActor->SetActorTransform(transform);
	}
}

void AHoldActor::SetLastTime(int32 value) {
	UE_LOG(LogTemp, Warning, TEXT("LastTime Set: %d\n"), value);
	lastTime = value;
	liveTime = lastTime + 1500;
}


void AHoldActor::SetSpawned(bool value) {
	spawned = value;
}

void AHoldActor::SetHitTime(int32 t) {
	hitTime = t;
}

void AHoldActor::SetEndTime(int32 t) {
	endTime = t;
}
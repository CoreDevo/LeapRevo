// Fill out your copyright notice in the Description page of Project Settings.

#include "osu3d_cpp.h"
#include "ArrowActor.h"


// Sets default values
AArrowActor::AArrowActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	liveTime = 1800;
	spawned = false;
}

// Called when the game starts or when spawned
void AArrowActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("An Arrow has spawned"));
}

// Called every frame
void AArrowActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	liveTime -= (int)(DeltaTime * 1000);
	if (liveTime < 1750 && !spawned) {
		spawned = true;
		FTransform transform = ActorToWorld();
		FTransform offset;
		offset.SetLocation(FVector(-200, 0, 0));
		transform.Accumulate(offset);
		moveActor = GetWorld()->SpawnActor<AArrowActor>(GetClass(), transform);

		TArray<UStaticMeshComponent *> mesh;
		moveActor->GetComponents<UStaticMeshComponent>(mesh);
		UE_LOG(LogTemp, Warning, TEXT("Found Static Mesh: %d\n"), mesh.Num());

		mesh[0]->SetMaterial(0, videoPlayerMaterial);

		moveActor->SetSpawned(true);
	}
	if (liveTime < 300 && moveActor) {
		moveActor->SetActorTransform(ActorToWorld());
	}
	else if (liveTime < 1750 && moveActor) {
		FTransform transform = ActorToWorld();
		FTransform offset;
		offset.SetLocation(FVector(-200 * ((float)(liveTime - 300) / 1450), 0, 0));
		transform.Accumulate(offset);
		moveActor->SetActorTransform(transform);
	}
	if (liveTime < 0) {
		Destroy();
	}
}

void AArrowActor::SetSpawned(bool value) {
	spawned = value;
}

void AArrowActor::SetHitTime(int32 t) {
	hitTime = t;
}

void AArrowActor::SetDirection(UNodeDirection dir) {
	direction = dir;
}


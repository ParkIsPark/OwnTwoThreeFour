// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/PerformerManager.h"
#include "Data/StageDataAsset.h"

// Sets default values
APerformerManager::APerformerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APerformerManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APerformerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APerformerManager::SetPerformerData(const TArray<FPerformerSpawnData>& InPerformerSpawnData)
{
	PerformerSpawnData = InPerformerSpawnData;
}




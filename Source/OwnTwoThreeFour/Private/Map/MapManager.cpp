// Fill out your copyright notice in the Description page of Project Settings.


#include "Map/MapManager.h"
#include "Data/StageDataAsset.h"
#include "Pawn/Performer.h"
#include "Map/Tile.h"

// Sets default values
AMapManager::AMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMapManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMapManager::SetMapData(const UStageDataAsset* StageData)
{
	// 유효성 검증 
	if (StageData == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("스테이지 데이터가 올바르지 않습니다"));
		return;
	}

	//=======================================
	// 로직 1 : 데이터 배치
	//==========================================
	TileSpawnData = StageData->TileSpawnData;
	PerformerSpawnData = StageData->PerformerSpawnData;

	GridHeight = StageData->GridHeight;
	GridWidth = StageData->GridWidth;


}


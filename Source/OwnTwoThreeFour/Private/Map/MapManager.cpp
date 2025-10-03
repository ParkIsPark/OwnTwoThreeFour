// Fill out your copyright notice in the Description page of Project Settings.


#include "Map/MapManager.h"
#include "Data/StageDataAsset.h"
#include "Pawn/Performer.h"
#include "Setting/MapSetting.h"
#include "Map/Tile.h"

// Sets default values
AMapManager::AMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnPoint = FVector(0.0f, 0.0f, 0.0f);// 몰라시발일단하드코딩으로때워

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


void AMapManager::SetMapSize(const FIntPoint& Size)
{
	GridWidth = Size.X;
	GridHeight = Size.Y;
}

void AMapManager::SetTileSpawnData(const TArray<FTileSpawnData>& InTileSpawnData)
{
	TileSpawnData = InTileSpawnData;
}

/** 맵을 스폰합니다*/
void AMapManager::SpawnMap()
{
	const UMapSettings* MapSettings = GetDefault<UMapSettings>();
	FRotator Rotation(0.0f, 0.0f, 0.0f);

	for (const FTileSpawnData& SpawnTileData : TileSpawnData) {
		FVector SpawnVector = SpawnPoint;
		SpawnVector.X = SpawnPoint.X + SpawnTileData.InitialCoordinates.X * MapSettings->TileSize;
		SpawnVector.Y = SpawnPoint.Y + SpawnTileData.InitialCoordinates.Y * MapSettings->TileSize;
		ATile* SpawnTile = GetWorld()->SpawnActor<ATile>(SpawnTileData.TileClass, SpawnVector, Rotation);
	}
}




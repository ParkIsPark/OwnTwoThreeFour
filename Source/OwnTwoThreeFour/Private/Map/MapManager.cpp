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
	// ��ȿ�� ���� 
	if (StageData == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("�������� �����Ͱ� �ùٸ��� �ʽ��ϴ�"));
		return;
	}

	//=======================================
	// ���� 1 : ������ ��ġ
	//==========================================
	TileSpawnData = StageData->TileSpawnData;
	PerformerSpawnData = StageData->PerformerSpawnData;

	GridHeight = StageData->GridHeight;
	GridWidth = StageData->GridWidth;


}


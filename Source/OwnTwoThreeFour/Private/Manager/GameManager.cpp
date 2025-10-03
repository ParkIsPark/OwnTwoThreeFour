// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/GameManager.h"
#include "Map/MapManager.h"
#include "Data/StageDataAsset.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameManager::SetStageData(const UStageDataAsset* StageDataAsset)
{
	// 유효성 검증 
	if (StageDataAsset == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("스테이지 데이터가 올바르지 않습니다"));
		return;
	}

	//=======================================
	// 로직 1. 매니저 데이터 초기화
	//==========================================
	MapManager->SetMapData(StageDataAsset);	

}

void AGameManager::StartGame()
{
	PlayerState = EPlayerState::EPS_Puzzle; // 플레이어가 퍼즐을 푸는 상태임을 확인합니다. 

	//TODO : 맵 매니저 -> 게임 시작

}


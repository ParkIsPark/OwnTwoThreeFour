// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/GameManager.h"
#include "Map/MapManager.h"
#include "Pawn/PerformerManager.h"
#include "CameraPuzzleGameMode.h"
#include "Data/StageDataAsset.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//기본값 초기화
	bAllManagerReady = false;

	// 브로드캐스트 함수 연결
	// 결과 : Gamemode에서 매니저를 다 만들어야만 작동 가능하도록 바뀜. 
	ACameraPuzzleGameMode* GameMode = Cast<ACameraPuzzleGameMode>(UGameplayStatics::GetGameMode(this));
	GameMode->OnLoadCompleteFunc.AddDynamic(this, &AGameManager::CheckAllManagerIsReady);

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

void AGameManager::LoadStageData(UStageDataAsset* StageDataAsset)
{
	//유효성 검증 1 : 모든 매니저가 로딩된 상황인가?
	if (bAllManagerReady == false)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] 매니저가 로딩되지 않은 상태에서 스테이지 초기화를 시도했습니다"), *GetName());
		return;
	}
	// 유효성 검증 
	if (StageDataAsset == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("[%s] 스테이지 데이터가 정상적이지 않습니다"), *GetName());
		return;
	}
	//스테이지 데이터 세팅으로 넘어갑니다.
	currentStageDataAsset = StageDataAsset;

	SetStageData(); 
}


void AGameManager::SetStageData()
{
	

	//=======================================
	// 로직 1. 매니저 데이터 초기화
	//==========================================
	MapManager->SetMapSize(currentStageDataAsset->GetGridSize());
	MapManager->SetTileSpawnData(currentStageDataAsset->GetTileSpawnData());

	PerformerManager->SetPerformerData(currentStageDataAsset->GetPerformerSpawnData());

	//=======================================
	// 로직 2. 본인 데이터 초기화
	//==========================================
	TimeLineTrack = currentStageDataAsset->GetTimelineTrack();

	// 모든게 끝났으면 -> 게임 스타트
	StartGame();
}

void AGameManager::StartGame()
{
	PlayerState = EPlayerState::EPS_Puzzle; // 플레이어가 퍼즐을 푸는 상태임을 확인합니다. 

	//TODO : 맵 매니저 -> 게임 시작
	MapManager->SpawnMap();
}


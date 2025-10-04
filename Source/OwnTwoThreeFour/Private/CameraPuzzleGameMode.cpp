// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPuzzleGameMode.h"
#include "Map/MapManager.h"
#include "Manager/GameManager.h"
#include "Pawn/PerformerManager.h"

void ACameraPuzzleGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	// 매니저 스폰
	SpawnManager();
	
}

void ACameraPuzzleGameMode::SpawnManager()
{
	//=======================================
	// 매니저 스폰
	//==========================================

	// 1. MapManager를 스폰
	SpawnedMapManager = GetWorld()->SpawnActor<AMapManager>();

	// 2. GameManager를 스폰
	SpawnedGameManager = GetWorld()->SpawnActor<AGameManager>();

	// 3. PerforemrManager 스폰
	SpawnedPerformerManager = GetWorld()->SpawnActor<APerformerManager>();

	//유효성 검사
	if (SpawnedMapManager && SpawnedGameManager) {

		// 1. 아웃라이어 창에서 활용할 레이블 할당
		SpawnedMapManager->SetActorLabel(TEXT("MapManager"));
		SpawnedGameManager->SetActorLabel(TEXT("GameManager"));
		SpawnedPerformerManager->SetActorLabel(TEXT("PerformerManager"));

		//2. 게임 매니저에 맵 매니저 할당.
		SpawnedGameManager->SetMapManager(SpawnedMapManager);
		SpawnedGameManager->SetPerformerManager(SpawnedPerformerManager);

		//3. 이후 GameManager에 BroadCast해서, 모든 매니저를 사용할 수 있음을 알림.
		OnLoadCompleteFunc.Broadcast();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("핵심 매니저 스폰에 실패했습니다!"));
	}
}


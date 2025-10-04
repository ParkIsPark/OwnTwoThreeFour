// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CameraPuzzleGameMode.generated.h"
class AGameManager;
class APerformerManager;
class AMapManager;
/**
 * 게임 모드입니다
 */
UCLASS()
class OWNTWOTHREEFOUR_API ACameraPuzzleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	//=======================================
	// 매니저들을 받아오는 Gettet/Setter
	//==========================================
	TObjectPtr<class AGameManager> GetGameManager() const{ return SpawnedGameManager;  }
	TObjectPtr<class APerformerManager> GetPerformerManager() const { return SpawnedPerformerManager; }
	TObjectPtr<class AMapManager> GetMapManager() const { return SpawnedMapManager; }

protected:
	virtual void BeginPlay() override;
private:
	//매니저들입니다
	TObjectPtr<class AGameManager> SpawnedGameManager;
	TObjectPtr<class APerformerManager> SpawnedPerformerManager;
	TObjectPtr<class AMapManager> SpawnedMapManager;
};

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
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoadingComplete);

UCLASS()
class OWNTWOTHREEFOUR_API ACameraPuzzleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	//=======================================
	// 매니저들을 받아오는 Gettet/Setter
	//==========================================
	UFUNCTION(BlueprintPure, Category = "Managers")
	AGameManager* GetGameManager() const{ return SpawnedGameManager;  }
	UFUNCTION(BlueprintPure, Category = "Managers")
	APerformerManager* GetPerformerManager() const { return SpawnedPerformerManager; }
	UFUNCTION(BlueprintPure, Category = "Managers")
	AMapManager* GetMapManager() const { return SpawnedMapManager; }


	/** Gamemode의 로딩이 끝난 후의 동작을 위한 델리게이트용 함수입니다.*/
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnLoadingComplete OnLoadCompleteFunc;

protected:
	virtual void BeginPlay() override;

	/** 매니저 스폰 로직*/
	void SpawnManager();

	

private:
	//매니저들입니다
	TObjectPtr<class AGameManager> SpawnedGameManager;
	TObjectPtr<class APerformerManager> SpawnedPerformerManager;
	TObjectPtr<class AMapManager> SpawnedMapManager;
};

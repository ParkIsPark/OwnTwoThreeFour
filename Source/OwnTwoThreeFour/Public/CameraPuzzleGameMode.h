// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CameraPuzzleGameMode.generated.h"
class AGameManager;
class APerformerManager;
class AMapManager;
/**
 * ���� ����Դϴ�
 */
UCLASS()
class OWNTWOTHREEFOUR_API ACameraPuzzleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	//=======================================
	// �Ŵ������� �޾ƿ��� Gettet/Setter
	//==========================================
	TObjectPtr<class AGameManager> GetGameManager() const{ return SpawnedGameManager;  }
	TObjectPtr<class APerformerManager> GetPerformerManager() const { return SpawnedPerformerManager; }
	TObjectPtr<class AMapManager> GetMapManager() const { return SpawnedMapManager; }

protected:
	virtual void BeginPlay() override;
private:
	//�Ŵ������Դϴ�
	TObjectPtr<class AGameManager> SpawnedGameManager;
	TObjectPtr<class APerformerManager> SpawnedPerformerManager;
	TObjectPtr<class AMapManager> SpawnedMapManager;
};

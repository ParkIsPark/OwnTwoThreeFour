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
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoadingComplete);

UCLASS()
class OWNTWOTHREEFOUR_API ACameraPuzzleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	//=======================================
	// �Ŵ������� �޾ƿ��� Gettet/Setter
	//==========================================
	UFUNCTION(BlueprintPure, Category = "Managers")
	AGameManager* GetGameManager() const{ return SpawnedGameManager;  }
	UFUNCTION(BlueprintPure, Category = "Managers")
	APerformerManager* GetPerformerManager() const { return SpawnedPerformerManager; }
	UFUNCTION(BlueprintPure, Category = "Managers")
	AMapManager* GetMapManager() const { return SpawnedMapManager; }


	/** Gamemode�� �ε��� ���� ���� ������ ���� ��������Ʈ�� �Լ��Դϴ�.*/
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnLoadingComplete OnLoadCompleteFunc;

protected:
	virtual void BeginPlay() override;

	/** �Ŵ��� ���� ����*/
	void SpawnManager();

	

private:
	//�Ŵ������Դϴ�
	TObjectPtr<class AGameManager> SpawnedGameManager;
	TObjectPtr<class APerformerManager> SpawnedPerformerManager;
	TObjectPtr<class AMapManager> SpawnedMapManager;
};

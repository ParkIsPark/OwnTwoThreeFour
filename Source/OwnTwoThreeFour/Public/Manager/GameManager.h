// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/CameraPuzzleTypes.h"
#include "GameManager.generated.h"

class AMapManager;
class UStageDataAsset;

/**
* 게임의 전반적인 상황을 총괄합니다.
*/
UCLASS()
class OWNTWOTHREEFOUR_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	/** 게임을 시작합니다*/
	void StartGame();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	EPlayerState PlayerState; // 플레이어의 상태입니다.

	//맵 매니저
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager")
	AMapManager* MapManager;

	//TODO : 스테이지 데이터 받는 로직 만들어야 함.


	UFUNCTION()
	/**
	* 스테이지 데이터를 받아서 시작할 준비를 합니다.
	*/
	void SetStageData(const UStageDataAsset* StageDataAsset);

};

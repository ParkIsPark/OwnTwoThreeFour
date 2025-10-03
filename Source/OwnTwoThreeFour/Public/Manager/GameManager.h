// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/CameraPuzzleTypes.h"
#include "GameManager.generated.h"

class AMapManager;
class APerformerManager;
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

	//TODO : 이거 플레이어컨트롤쪽으로 넘겨줘야 함.
	UPROPERTY(VisibleAnywhere, Category = "GameState")
	EPlayerState PlayerState; // 플레이어의 상태입니다. 

	UPROPERTY(VisibleAnywhere, Category="GameState")
	TArray<int32> TimeLineTrack;

	//맵 매니저
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager")
	AMapManager* MapManager;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Manager")
	APerformerManager* PerformerManager;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager")
	UStageDataAsset* testDataSet;
	//TODO : 스테이지 데이터 받는 로직 만들어야 함.


	UFUNCTION()
	/**
	* 스테이지 데이터를 받아서 시작할 준비를 합니다.
	*/
	void SetStageData(const UStageDataAsset* StageDataAsset);

};

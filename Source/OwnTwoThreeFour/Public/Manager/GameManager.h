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
	/** 스테이지 데이터를 로드해옵니다.*/
	UFUNCTION()
	void LoadStageData(UStageDataAsset* StageDataAsset);


	// Sets default values for this actor's properties
	AGameManager();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//TODO : 이거 플레이어컨트롤쪽으로 넘겨줘야 함.
	UPROPERTY(VisibleAnywhere, Category = "GameState")
	EPlayerState PlayerState; // 플레이어의 상태입니다. 


	//=======================================
	// Getter / Setter 섹션
	//==========================================
	// Getters
	UFUNCTION(BlueprintPure, Category = "GameState")
	FORCEINLINE TArray<int32> GetTimeLineTrack() const { return TimeLineTrack; }

	UFUNCTION(BlueprintPure, Category = "Manager")
	FORCEINLINE AMapManager* GetMapManager() const { return MapManager; }

	UFUNCTION(BlueprintPure, Category = "Manager")
	FORCEINLINE APerformerManager* GetPerformerManager() const { return PerformerManager; }

	UFUNCTION(BlueprintPure, Category = "Manager")
	FORCEINLINE UStageDataAsset* GetCurrentStageDataAsset() const { return currentStageDataAsset; }

	// Setters
	UFUNCTION(BlueprintCallable, Category = "GameState")
	FORCEINLINE void SetTimeLineTrack(const TArray<int32>& InTimeLineTrack) { TimeLineTrack = InTimeLineTrack; }

	UFUNCTION(BlueprintCallable, Category = "Manager")
	FORCEINLINE void SetMapManager(AMapManager* InMapManager) { MapManager = InMapManager; }

	UFUNCTION(BlueprintCallable, Category = "Manager")
	FORCEINLINE void SetPerformerManager(APerformerManager* InPerformerManager) { PerformerManager = InPerformerManager; }

	UFUNCTION(BlueprintCallable, Category = "Manager")
	FORCEINLINE void SetCurrentStageDataAsset(UStageDataAsset* InStageDataAsset) { currentStageDataAsset = InStageDataAsset; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** 모든 매니저가 준비되었다면 바뀝니다 */
	UFUNCTION(BlueprintCallable, Category = "Util")
	FORCEINLINE void CheckAllManagerIsReady() { bAllManagerReady = true; }


	/**스테이지 데이터를 받아서 시작할 준비를 합니다.*/
	UFUNCTION()
	void SetStageData();


	/** 게임을 시작합니다*/
	UFUNCTION()
	void StartGame();

	
private:
	/** 타임라인 트랙 정보*/
	UPROPERTY(VisibleAnywhere, Category = "GameState", meta = (AllowPrivateAccess = "true"))
	TArray<int32> TimeLineTrack;

	/**맵 매니저*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AMapManager> MapManager;

	/**퍼포머 매니저*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<APerformerManager> PerformerManager;

	/**현재 스테이지 데이터 인포*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStageDataAsset> currentStageDataAsset;

	/** 모든 매니저가 로딩되었는가? */
	int32 bAllManagerReady : 1;



};
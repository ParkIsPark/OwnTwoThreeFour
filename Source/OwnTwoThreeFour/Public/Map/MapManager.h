// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/CameraPuzzleTypes.h"
#include "MapManager.generated.h"

class UStageDataAsset;
class ATile;

UCLASS()
class OWNTWOTHREEFOUR_API AMapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** 스폰이 시작될 기준 위치입니다*/
	UPROPERTY(EditAnywhere, Category = "Property")
	FVector SpawnPoint;
	/** 이 스테이지 그리드의 가로 크기입니다. */
	UPROPERTY(EditAnywhere, Category = "Property")
	int32 GridWidth;

	/** 이 스테이지 그리드의 세로 크기입니다. */
	UPROPERTY(EditAnywhere, Category = "Property")
	int32 GridHeight;

	/** * 그리드 레이아웃 데이터입니다. (GridWidth * GridHeight)개의 원소를 가져야 합니다.
	* 배열의 첫 번째 원소는 (0,0), 마지막 원소는 (Width-1, Height-1)에 해당합니다.
	*/
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<FTileSpawnData> TileSpawnData;

	/** 
	* 실제 스폰한 타일 액터를 가지고 있습니다..
	* 2차원 배열을 1차원으로 늘려 편 위치상의 데이터 그대로 가지고 있습니다.
	*/
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<ATile*> TileArray;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	/** 맵의 사이즈를 설정합니다*/
	UFUNCTION()
	void SetMapSize(const FIntPoint& Size);
	/**맵의 타일 스폰 데이터를 설정합니다*/
	UFUNCTION()
	void SetTileSpawnData(const TArray<FTileSpawnData>& InTileSpawnData);

	/**맵을 스폰합니다*/
	UFUNCTION()
	void SpawnMap();
	

	//TODO : 그리드 출력 만들어야 함. 
	//TODO : 데이터 기반으로 바닥 출력하는거 만들어야 함.

};

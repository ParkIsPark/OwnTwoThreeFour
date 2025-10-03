// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/CameraPuzzleTypes.h"
#include "StageDataAsset.generated.h"

/**
 * 스테이지 데이터에 대한 정보입니다. 
 */ 
UCLASS()
class OWNTWOTHREEFOUR_API UStageDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
    /** 이 스테이지 그리드의 가로 크기입니다. */
    UPROPERTY(EditAnywhere,Category = "Map", meta = (AllowPrivateAccess = "true"))
    int32 GridWidth;

    /** 이 스테이지 그리드의 세로 크기입니다. */
    UPROPERTY(EditAnywhere, Category = "Map", meta = (AllowPrivateAccess = "true"))
    int32 GridHeight;

    /** * 그리드 레이아웃 데이터입니다. (GridWidth * GridHeight)개의 원소를 가져야 합니다.
     * 배열의 첫 번째 원소는 (0,0), 마지막 원소는 (Width-1, Height-1)에 해당합니다.
     */
    UPROPERTY(EditAnywhere,  Category = "Grid", meta = (AllowPrivateAccess = "true"))
    TArray<FTileSpawnData> TileSpawnData;

    /** 이 스테이지에 스폰될 Performer들의 정보 목록입니다. */
    UPROPERTY(EditAnywhere, Category = "Performer", meta = (AllowPrivateAccess = "true"))
    TArray<FPerformerSpawnData> PerformerSpawnData;

    /** 이 스테이지의 타임라인 트랙입니다. */
    UPROPERTY(EditAnywhere, Category = "Timeline", meta = (AllowPrivateAccess = "true"))
    TArray<int32> TimelineTrack;
	
};

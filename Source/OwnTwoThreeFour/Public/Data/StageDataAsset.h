// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/CameraPuzzleTypes.h"
#include "StageDataAsset.generated.h"

/**
 * �������� �����Ϳ� ���� �����Դϴ�. 
 */ 
UCLASS()
class OWNTWOTHREEFOUR_API UStageDataAsset : public UDataAsset
{
	GENERATED_BODY()
private:
    /** �� �������� �׸����� ���� ũ���Դϴ�. */
    UPROPERTY(EditAnywhere,Category = "Map", meta = (AllowPrivateAccess = "true"))
    int32 GridWidth;

    /** �� �������� �׸����� ���� ũ���Դϴ�. */
    UPROPERTY(EditAnywhere, Category = "Map", meta = (AllowPrivateAccess = "true"))
    int32 GridHeight;

    /** * �׸��� ���̾ƿ� �������Դϴ�. (GridWidth * GridHeight)���� ���Ҹ� ������ �մϴ�.
     * �迭�� ù ��° ���Ҵ� (0,0), ������ ���Ҵ� (Width-1, Height-1)�� �ش��մϴ�.
     */
    UPROPERTY(EditAnywhere,  Category = "Grid", meta = (AllowPrivateAccess = "true"))
    TArray<FTileSpawnData> TileSpawnData;

    /** �� ���������� ������ Performer���� ���� ����Դϴ�. */
    UPROPERTY(EditAnywhere, Category = "Performer", meta = (AllowPrivateAccess = "true"))
    TArray<FPerformerSpawnData> PerformerSpawnData;

    /** �� ���������� Ÿ�Ӷ��� Ʈ���Դϴ�. */
    UPROPERTY(EditAnywhere, Category = "Timeline", meta = (AllowPrivateAccess = "true"))
    TArray<int32> TimelineTrack;

public:
    //======================================================================
    // ACCESSORS / GETTERS
    //======================================================================

    /** �׸����� ����, ���� ũ�⸦ FIntPoint�� ��ȯ�մϴ�. */
    UFUNCTION(BlueprintPure, Category = "StageData")
    FIntPoint GetGridSize() const { return FIntPoint(GridWidth, GridHeight); }

    /** �׸��� Ÿ�� ���̾ƿ� �����͸� const ������ ��ȯ�մϴ�. (���� ����) */
    UFUNCTION(BlueprintPure, Category = "StageData")
    const TArray<FTileSpawnData> GetTileSpawnData() const { return TileSpawnData; }

    /** ������ Performer���� ������ ����� const ������ ��ȯ�մϴ�. */
    UFUNCTION(BlueprintPure, Category = "StageData")
    const TArray<FPerformerSpawnData>& GetPerformerSpawnData() const { return PerformerSpawnData; }

    /** Ÿ�Ӷ��� Ʈ�� �����͸� const ������ ��ȯ�մϴ�. */
    UFUNCTION(BlueprintPure, Category = "StageData")
    const TArray<int32>& GetTimelineTrack() const { return TimelineTrack; }
};

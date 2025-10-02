// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Data/CameraPuzzleTypes.h"
#include "StageInfo.generated.h"

/**
 * 
 */
UCLASS()
class OWNTWOTHREEFOUR_API AStageInfo : public AInfo
{
	GENERATED_BODY()

public:
    /** �� �������� �׸����� ���� ũ���Դϴ�. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Map")
    int32 GridWidth;

    /** �� �������� �׸����� ���� ũ���Դϴ�. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Map")
    int32 GridHeight;

    /** * �׸��� ���̾ƿ� �������Դϴ�. (GridWidth * GridHeight)���� ���Ҹ� ������ �մϴ�.
     * �迭�� ù ��° ���Ҵ� (0,0), ������ ���Ҵ� (Width-1, Height-1)�� �ش��մϴ�.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid")
    TArray<FTileSpawnData> TileSpawnData;

    /** �� ���������� ������ Performer���� ���� ����Դϴ�. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performer")
    TArray<FPerformerSpawnData> PerformerSpawnData;

    /** �� ���������� Ÿ�Ӷ��� Ʈ���Դϴ�. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timeline")
    TArray<int32> TimelineTrack;


private:


	
};

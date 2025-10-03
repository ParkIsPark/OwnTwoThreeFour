// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/CameraPuzzleTypes.h"
#include "Tile.generated.h"

UCLASS()
class OWNTWOTHREEFOUR_API ATile : public AActor
{
	GENERATED_BODY()
	
public:
    ATile();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile|Components")
    USceneComponent* Root; // 컴포넌트들을 담을 루트 컴포넌트입니다.

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile|Components")
    UStaticMeshComponent* FloorMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile|Components")
    UStaticMeshComponent* ObstacleMesh;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile")
    ETileType TileType;

    //TODO : 타일 스폰 규칙 정의해야 함.

public:
    // 이 타일이 장애물을 가지고 있는지 (ObstacleMesh에 유효한 매쉬가 할당되었는지)를 확인하는 함수입니다.
    UFUNCTION(BlueprintPure, Category = "Tile")
    bool HasObstacle() const;

    UFUNCTION(BlueprintPure, Category = "Tile")
    ETileType GetTileType() const { return TileType; }
};

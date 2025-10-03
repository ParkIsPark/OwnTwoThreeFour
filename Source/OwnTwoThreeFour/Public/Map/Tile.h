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
    USceneComponent* Root; // ������Ʈ���� ���� ��Ʈ ������Ʈ�Դϴ�.

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile|Components")
    UStaticMeshComponent* FloorMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile|Components")
    UStaticMeshComponent* ObstacleMesh;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile")
    ETileType TileType;

    //TODO : Ÿ�� ���� ��Ģ �����ؾ� ��.

public:
    // �� Ÿ���� ��ֹ��� ������ �ִ��� (ObstacleMesh�� ��ȿ�� �Ž��� �Ҵ�Ǿ�����)�� Ȯ���ϴ� �Լ��Դϴ�.
    UFUNCTION(BlueprintPure, Category = "Tile")
    bool HasObstacle() const;

    UFUNCTION(BlueprintPure, Category = "Tile")
    ETileType GetTileType() const { return TileType; }
};

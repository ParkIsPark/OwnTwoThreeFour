// Fill out your copyright notice in the Description page of Project Settings.


#include "Map/Tile.h"

// Sets default values
ATile::ATile()
{
    // Ÿ���� �� ������ ������Ʈ�� �ʿ䰡 �����Ƿ� Tick�� ���ϴ�. (���� ����ȭ)
    PrimaryActorTick.bCanEverTick = false;

    // 1. ��Ʈ ������Ʈ�� �����մϴ�.
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = Root;

    // 2. FloorMesh ������Ʈ�� �����ϰ� ��Ʈ�� ���Դϴ�(Attach).
    FloorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorMesh"));
    FloorMesh->SetupAttachment(RootComponent);

    // 3. ObstacleMesh ������Ʈ�� �����ϰ� ��Ʈ�� ���Դϴ�.
    //    �� ������Ʈ�� C++������ ����ִ� 'Ʋ' ���Ҹ� �մϴ�.
    //    ���� �Ž� �Ҵ��� �������Ʈ���� �̷�����ϴ�.
    ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleMesh"));
    ObstacleMesh->SetupAttachment(RootComponent);

}

bool ATile::HasObstacle() const
{
    // ObstacleMesh ������Ʈ�� �����ϰ�, �� ������Ʈ�� ��ȿ�� ����ƽ �Ž��� �Ҵ�Ǿ� �ִ��� Ȯ���մϴ�.
    return (ObstacleMesh != nullptr && ObstacleMesh->GetStaticMesh() != nullptr);
}




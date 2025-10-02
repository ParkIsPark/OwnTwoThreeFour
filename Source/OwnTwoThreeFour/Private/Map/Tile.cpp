// Fill out your copyright notice in the Description page of Project Settings.


#include "Map/Tile.h"

// Sets default values
ATile::ATile()
{
    // 타일은 매 프레임 업데이트할 필요가 없으므로 Tick을 끕니다. (성능 최적화)
    PrimaryActorTick.bCanEverTick = false;

    // 1. 루트 컴포넌트를 생성합니다.
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = Root;

    // 2. FloorMesh 컴포넌트를 생성하고 루트에 붙입니다(Attach).
    FloorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorMesh"));
    FloorMesh->SetupAttachment(RootComponent);

    // 3. ObstacleMesh 컴포넌트를 생성하고 루트에 붙입니다.
    //    이 컴포넌트는 C++에서는 비어있는 '틀' 역할만 합니다.
    //    실제 매쉬 할당은 블루프린트에서 이루어집니다.
    ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleMesh"));
    ObstacleMesh->SetupAttachment(RootComponent);

}

bool ATile::HasObstacle() const
{
    // ObstacleMesh 컴포넌트가 존재하고, 그 컴포넌트에 유효한 스태틱 매쉬가 할당되어 있는지 확인합니다.
    return (ObstacleMesh != nullptr && ObstacleMesh->GetStaticMesh() != nullptr);
}




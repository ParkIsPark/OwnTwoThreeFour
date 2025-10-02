// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraPuzzleTypes.generated.h" // UHT(Unreal Header Tool)를 위한 헤더

// 게임의 전체적인 상태를 정의하는 열거형(Enum)입니다.
UENUM(BlueprintType)
enum class EGameState : uint8
{
    EGS_Planning    UMETA(DisplayName = "Planning"), // 기획 단계
    EGS_Executing   UMETA(DisplayName = "Executing") // 실행 단계
};

// Performer가 수행할 수 있는 행동의 종류를 정의하는 열거형입니다.
UENUM(BlueprintType)
enum class EActionType : uint8
{
    EAT_None        UMETA(DisplayName = "None"),
    EAT_MoveUp      UMETA(DisplayName = "Move Up"),
    EAT_MoveDown    UMETA(DisplayName = "Move Down"),
    EAT_MoveLeft    UMETA(DisplayName = "Move Left"),
    EAT_MoveRight   UMETA(DisplayName = "Move Right"),
    EAT_Wait        UMETA(DisplayName = "Wait")
};

// 타일의 종류를 정의하는 열거형입니다.
UENUM(BlueprintType)
enum class ETileType : uint8
{
    ETT_Empty       UMETA(DisplayName = "Empty"), // 빈 타일
    ETT_Wall        UMETA(DisplayName = "Wall"),  // 벽
    ETT_Dest        UMETA(DisplayName = "Dest")   // 목적지, 테스트 빌드에선 하나만 넣을 예정
};

// StageData에서 Performer를 스폰할 때 사용할 정보를 담는 구조체(Struct)입니다.
USTRUCT(BlueprintType)
struct FPerformerSpawnData
{
    GENERATED_BODY()

    // 어떤 종류의 Performer를 스폰할지
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<class APerformer> PerformerClass;

    // 어느 그리드 좌표에 스폰할지
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FIntPoint InitialCoordinates;
};

USTRUCT(BlueprintType)
struct FTileSpawnData
{
    GENERATED_BODY()

    // 어떤 종류의 타일을
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<class ATile> TileClass;

    // 어느 그리드 좌표에 스폰할지
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FIntPoint InitialCoordinates;
};
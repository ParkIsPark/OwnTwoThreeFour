// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestButton_Map.generated.h"
class UButton;
class UStageDataAsset;
/**
 * �׽�Ʈ������ ����ϴ� ��ư�Դϴ�.
 */
UCLASS()
class OWNTWOTHREEFOUR_API UTestButton_Map : public UUserWidget
{

	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* LoadButton;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStageDataAsset> TestStageData;

	UFUNCTION()
	void LoadButtonClicked();

	virtual void NativeConstruct() override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameFieldBase.h"
#include "QuoridorGameState.generated.h"

UCLASS()
class QUORIDOR_API AQuoridorGameState : public AGameStateBase{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category="Configuration")
	TSubclassOf<AGameFieldBase> GameFieldClass;
public:	
	AGameFieldBase *GameField = nullptr;
public:
	void BeginPlay()override;
};

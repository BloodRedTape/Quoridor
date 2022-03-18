// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Tile.h"
#include "QuoridorFieldState.generated.h"

/**
 * 
 */
UCLASS()
class QUORIDOR_API AQuoridorFieldState : public AGameStateBase{
	GENERATED_BODY()
private:
	static constexpr size_t FieldSize = 8;
	bool TileMap[FieldSize][FieldSize] = {};
	bool BorderMap[FieldSize - 1][FieldSize - 1] = {};

	UPROPERTY(EditAnywhere, Category="Configuration")
	TSubclassOf<ATile> TileClass;
public:

	void BeginPlay()override;

	void SpawnBorder(FVector2D position){

	}
};

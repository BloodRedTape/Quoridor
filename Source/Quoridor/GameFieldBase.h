#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TileBase.h"
#include "GameFieldBase.generated.h"

UCLASS()
class QUORIDOR_API AGameFieldBase: public AActor{
	GENERATED_BODY()
private:
	static constexpr size_t FieldSize = 8;

	bool TileMap[FieldSize][FieldSize] = {};

	bool BorderMap[FieldSize - 1][FieldSize - 1] = {};

	UPROPERTY(EditAnywhere, Category="Configuration")
	TSubclassOf<ATileBase> TileClass;
public:
	void BeginPlay()override;
};

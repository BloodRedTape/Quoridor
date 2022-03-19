#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameFieldBase.generated.h"

UCLASS()
class QUORIDOR_API AGameFieldBase: public AActor{
	GENERATED_BODY()
private:
	static constexpr size_t FieldSize = 8;

	bool TileMap[FieldSize][FieldSize] = {};

	bool BorderMap[FieldSize - 1][FieldSize - 1] = {};

	UPROPERTY(EditDefaultsOnly, Category="Configuration")
	UStaticMesh *TileMesh = nullptr;

	//UPROPERTY(VisibleAnywhere)
	USceneComponent *Root = nullptr;
public:
	AGameFieldBase(); 
	
	void PostInitProperties()override;
};

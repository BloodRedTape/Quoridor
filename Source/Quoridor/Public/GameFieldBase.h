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

	bool BorderMap[FieldSize][FieldSize] = {};

	UPROPERTY(EditDefaultsOnly, Category="Configuration")
	UStaticMesh *TileMesh = nullptr;
	UPROPERTY(EditDefaultsOnly, Category="Configuration")
	UStaticMesh *BorderMesh = nullptr;

	//UPROPERTY(VisibleAnywhere)
	USceneComponent *Root = nullptr;
public:
	AGameFieldBase(); 
	
	void BeginPlay()override;

	UFUNCTION(BlueprintCallable)
	void PlaceBorder(int x, int y);
private:
	void SpawnBorder(int x, int y);

	void SpawnTile(int x, int y);

	FVector2D GetTileSize(){
		FBox Box = TileMesh->GetBoundingBox();
    	return {Box.GetSize().X, Box.GetSize().Y};
	}

	FVector2D GetBorderSize(){
		FBox Box = BorderMesh->GetBoundingBox();
    	return {Box.GetSize().X, Box.GetSize().Y};
	}
};

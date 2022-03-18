#pragma once

#include "CoreMinimal.h"
#include "Tile.generated.h"

UCLASS()
class QUORIDOR_API ATile: public AActor{
    GENERATED_BODY()
private:
    UPROPERTY(VisibleAnywhere, Category="Visuals")
    UStaticMeshComponent *MeshComponent = nullptr;
public:
    ATile();

    FBox GetBoundingBox()const;
};
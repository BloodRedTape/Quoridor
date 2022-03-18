#pragma once

#include "CoreMinimal.h"
#include "TileBase.generated.h"

UCLASS()
class QUORIDOR_API ATileBase: public AActor{
    GENERATED_BODY()
private:
    UPROPERTY(VisibleAnywhere, Category="Visuals")
    UStaticMeshComponent *MeshComponent = nullptr;
public:
    ATileBase();

    FBox GetBoundingBox()const;
};
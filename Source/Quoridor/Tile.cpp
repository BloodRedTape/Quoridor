#include "Tile.h"

ATile::ATile(){
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

FBox ATile::GetBoundingBox()const{
    return MeshComponent->GetStaticMesh()->GetBoundingBox();
}
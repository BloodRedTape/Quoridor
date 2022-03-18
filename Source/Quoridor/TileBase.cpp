#include "TileBase.h"

ATileBase::ATileBase(){
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

FBox ATileBase::GetBoundingBox()const{
    return MeshComponent->GetStaticMesh()->GetBoundingBox();
}
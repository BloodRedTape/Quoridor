#include "GameFieldBase.h"

AGameFieldBase::AGameFieldBase(){
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

void AGameFieldBase::PostInitProperties() {
    Super::PostInitProperties();
    
    if(!TileMesh)return;

    FBox Box = TileMesh->GetBoundingBox();
    FVector2D BoxSize = {Box.GetSize().X, Box.GetSize().Y};
    FVector2D Cursor = {0.f, 0.f};

    for(int i = 0; i<FieldSize; i++){
        for(int j = 0; j<FieldSize; j++){
            UStaticMeshCompoennt* MeshComponent = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass());
            
            MeshComponent->SetStaticMesh(TileMesh);
            MeshComponent->SetRelativeLocation({Cursor.X, Cursor.Y, 0});

            MeshComponent->RegisterComponent();
            MeshComponent->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

            Cursor.X += BoxSize.X;
        }
        Cursor.X = 0;
        Cursor.Y += BoxSize.Y;
    }
}
#include "GameFieldBase.h"

AGameFieldBase::AGameFieldBase(){
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

void AGameFieldBase::PostInitProperties() {
    Super::PostInitProperties();
    
    if(!TileMesh)return;

    for(int i = 0; i<FieldSize; i++)
        for(int j = 0; j<FieldSize; j++)
            SpawnTile(i, j);
}

void AGameFieldBase::PlaceBorder(int x, int y){
    check(x < FieldSize - 1);
    check(y < FieldSize - 1);

    BorderMap[x][y] = true;

    SpawnBorder(x, y);
}

void AGameFieldBase::SpawnBorder(int x, int y){
    //check(x >= 0 && x < FieldSize - 1 + y%2);
    //check(y >= 0 && y < FieldSize);

    UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass());

    float lx = (GetTileSize().X / 2.f) * (1 - y % 2) + x * GetTileSize().X;
    float ly = y * (GetTileSize().Y / 2.f);
    float rot = 90 * (y % 2);
    FVector2D Location = {lx, ly};
    FRotator  Rotation = {0.f, rot, 0.f};
    
    MeshComponent->SetStaticMesh(BorderMesh);
    MeshComponent->SetRelativeLocation(FVector(Location, 0.f));
    MeshComponent->SetRelativeRotation(Rotation);

    MeshComponent->RegisterComponent();
    MeshComponent->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
}

void AGameFieldBase::SpawnTile(int x, int y){
    FVector2D BoxSize = GetTileSize();

    UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass());
    
    MeshComponent->SetStaticMesh(TileMesh);
    MeshComponent->SetRelativeLocation(FVector(FVector2D(x, y) * BoxSize, 0.f));

    MeshComponent->RegisterComponent();
    MeshComponent->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
}
#include "GameFieldBase.h"

void AGameFieldBase::BeginPlay(){
    FVector2D Cursor = {0.f, 0.f};
    FBox Box = TileClass->GetDefaultObject<ATileBase>()->GetBoundingBox();

    FVector2D BoxSize = {Box.GetSize().X, Box.GetSize().Y};

    for(int i = 0; i<FieldSize; i++){
        for(int j = 0; j<FieldSize; j++){
            ATileBase *Tile = GetWorld()->SpawnActor<ATileBase>(TileClass);
            Tile->SetActorLocation({Cursor.X, Cursor.Y, 0});
            Cursor.X += BoxSize.X;
            Tile->AttachToActor(this, {EAttachmentRule::KeepRelative, false});
        }
        Cursor.X = 0;
        Cursor.Y += BoxSize.Y;
    }
}
#include "QuoridorFieldState.h"
#include "Tile.h"

void AQuoridorFieldState::BeginPlay(){
    FVector2D Cursor = {0.f, 0.f};
    FBox Box = (NewObject<ATile>(this, TileClass))->GetBoundingBox();

    FVector2D BoxSize = {Box.GetSize().X, Box.GetSize().Y};

    for(int i = 0; i<FieldSize; i++){
        for(int j = 0; j<FieldSize; j++){
            ATile *Tile = (ATile*)GetWorld()->SpawnActor(TileClass);
            Tile->SetActorLocation({Cursor.X, Cursor.Y, 0});
            Cursor.X += BoxSize.X;
            Tile->AttachToActor(this, {EAttachmentRule::KeepRelative, false});
        }
        Cursor.X = 0;
        Cursor.Y += BoxSize.Y;
    }
}
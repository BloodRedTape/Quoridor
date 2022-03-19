#include "QuoridorGameState.h"
#include "GameFieldBase.h"

void AQuoridorGameState::BeginPlay(){
    Super::BeginPlay();

    if(!GameFieldClass)return;

    FVector Location = {};
    GameField = (AGameFieldBase*)GetWorld()->SpawnActor(GameFieldClass, &Location, nullptr);
}
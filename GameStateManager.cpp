#include "GameStateManager.h"

static int gameState = 0;

void ChangeStateTo(int newState)
{
    gameState = newState;
}

int GetGameState()
{
    return gameState;
}

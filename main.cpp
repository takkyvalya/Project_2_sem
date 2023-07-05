#include <iostream>
#include "Game.h"

int main() {
    mt::Game game;
    game.SetResolution(1920, 1056);
    game.SetCaption("Test game");
    game.Setup();
    game.Run();

    return 0;

}
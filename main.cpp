#include <iostream>

#include "BlackjackGame.h"

int main() {
    auto game = new BlackjackGame {};

    game->startGame();

    std::cout << game->gameStatus() << std::endl;

    return 0;
}

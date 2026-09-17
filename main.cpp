#include <iostream>

#include "BlackjackGame.h"

int main() {
    auto game = new BlackjackGame {};

    game->startGame();

    std::cout << game->printGameStatus() << std::endl;

    return 0;
}

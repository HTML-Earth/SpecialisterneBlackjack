#include <iostream>

#include "BlackjackGame.h"

int main() {
    auto game = new BlackjackGame {};

    game->startGame();

    std::cout << "Hello, World!" << std::endl;

    return 0;
}

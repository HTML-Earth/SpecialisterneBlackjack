#include <iostream>

#include "BlackjackGame.h"

int main() {
    auto game = new BlackjackGame {};

    game->startGame();

    std::cout << game->printGameStatus() << std::endl;

    while (game->getCurrentState() == BlackjackGame::playing) {
        std::string input = "";
        std::cin >> input;
        if (input == "hit") {
            game->hit();
        }
        if (input == "stay") {
            game->stay();
        }

        std::cout << game->printGameStatus() << std::endl;
    }

    return 0;
}

#include <iostream>
#include <fmt/core.h>
#include "BlackjackGame.h"

using namespace std;

int main() {
    bool applicationIsActive = true;
    auto game = new BlackjackGame {};

    fmt::print("== BLACKJACK ==\n");
    fmt::print("Type 'start' to start the game...\n");

    while (applicationIsActive) {
        string input;

        cin >> input;
        if (input == "start") {
            fmt::print("{}\n", game->startGame());
        }
        else if (input == "hit" || input == "draw") {
            fmt::print("{}\n", game->hit());
        }
        else if (input == "stand" || input == "stay") {
            fmt::print("{}\n", game->stand());
        }
        else if (input == "quit" || input == "exit") {
            applicationIsActive = false;
            fmt::print("Quitting application...\n");
        }
        else if (input == "short") {
            fmt::print("{}\n", game->toggleShort());
        }
        else {
            fmt::print("Invalid input.\n");
        }
    }

    return 0;
}

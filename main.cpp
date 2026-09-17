#include <iostream>

#include "BlackjackGame.h"

using namespace std;

int main() {
    auto game = new BlackjackGame {};

    game->startGame();

    cout << game->printGameStatus() << endl;

    while (game->getCurrentState() == BlackjackGame::playing) {
        string input;

        cin >> input;
        if (input == "hit") {
            game->hit();
        }
        if (input == "stay") {
            game->stay();
        }

        cout << game->printGameStatus() << endl;
    }

    return 0;
}

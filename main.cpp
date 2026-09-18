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
            cout << game->printGameStatus() << endl;
        }
        else if (input == "stay") {
            game->stay();
            cout << game->printGameStatus() << endl;
        }
        else {
            cout << "Invalid input." << endl;
        }
    }

    return 0;
}

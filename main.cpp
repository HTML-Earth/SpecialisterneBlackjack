#include <iostream>

#include "BlackjackGame.h"

using namespace std;

int main() {
    bool applicationIsActive = true;
    auto game = new BlackjackGame {};

    cout << "== BLACKJACK ==" << endl;
    cout << "Type 'start' to start the game..." << endl;

    while (applicationIsActive) {
        string input;

        cin >> input;
        if (input == "start") {
            cout << game->startGame() << endl;
        }
        else if (input == "hit" || input == "draw") {
            cout << game->hit() << endl;
        }
        else if (input == "stand" || input == "stay") {
            cout << game->stand() << endl;
        }
        else if (input == "quit" || input == "exit") {
            applicationIsActive = false;
            cout << "Quitting application..." << endl;
        }
        else if (input == "short") {
            cout << game->toggleShort() << endl;
        }
        else {
            cout << "Invalid input." << endl;
        }
    }

    return 0;
}

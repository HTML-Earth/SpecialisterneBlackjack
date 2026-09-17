//
// Created by Stefan on 17-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_BLACKJACKGAME_H
#define SPECIALISTERNEBLACKJACK_BLACKJACKGAME_H
#include "Spot.h"


class BlackjackGame {
private:
    Spot m_deck;
    Spot m_playerHand;
    Spot m_houseHand;
    void performHouseTurn();
    void checkWinner();
public:
    BlackjackGame();

    void startGame();
    void hit();
    void stay();
    std::string gameStatus();
};


#endif //SPECIALISTERNEBLACKJACK_BLACKJACKGAME_H

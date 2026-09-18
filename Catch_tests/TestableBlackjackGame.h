//
// Created by Stefan on 18-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_TESTABLEBLACKJACKGAME_H
#define SPECIALISTERNEBLACKJACK_TESTABLEBLACKJACKGAME_H
#include "../BlackjackGame.h"


class TestableBlackjackGame : public BlackjackGame {
public:
    GameState getCurrentState();
    int getCurrentRound();
    bool getPlayerStayed();
    bool getHouseStayed();
    EndCondition getEndCondition();
    Spot getDeck();
    Spot getPlayerHand();
    Spot getHouseHand();
};


#endif //SPECIALISTERNEBLACKJACK_TESTABLEBLACKJACKGAME_H

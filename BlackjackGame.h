//
// Created by Stefan on 17-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_BLACKJACKGAME_H
#define SPECIALISTERNEBLACKJACK_BLACKJACKGAME_H
#include "Spot.h"


class BlackjackGame {
public:
    enum GameState {
        inactive,
        playing,
        waitingForComputer,
        ended
    };
    enum EndCondition {
        none = NULL,
        playerWon,
        houseWon,
        tied
    };
private:
    GameState m_currentState;
    int m_currentRound;
    bool m_playerStayed;
    bool m_houseStayed;
    EndCondition m_endCondition;
    Spot m_deck;
    Spot m_playerHand;
    Spot m_houseHand;
    void performHouseTurn();
    void checkWinner();
    void endGame(EndCondition condition);
    static std::string printCardsInSpot(Spot& spot, bool hideFirstCard);
    std::string printCurrentHands();
    std::string printGameStatus();
public:
    BlackjackGame();

    GameState getCurrentState();
    std::string startGame();
    std::string hit();
    std::string stay();
};


#endif //SPECIALISTERNEBLACKJACK_BLACKJACKGAME_H

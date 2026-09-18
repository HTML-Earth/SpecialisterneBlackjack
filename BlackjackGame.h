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
protected:
    GameState m_currentState;
    int m_currentRound;
    bool m_playerStayed;
    bool m_houseStayed;
    EndCondition m_endCondition;
    Spot m_deck;
    Spot m_playerHand;
    Spot m_houseHand;
private:
    void performHouseTurn();
    void checkWinner();
    void endGame(EndCondition condition);
    static std::string printCardsInSpot(Spot& spot, bool hideFirstCard);
    std::string printCurrentHands();
    std::string printGameStatus();
public:
    BlackjackGame();

    std::string startGame();
    std::string hit();
    std::string stand();
};


#endif //SPECIALISTERNEBLACKJACK_BLACKJACKGAME_H

//
// Created by Stefan on 18-Sep-26.
//

#include "TestableBlackjackGame.h"

BlackjackGame::GameState TestableBlackjackGame::getCurrentState() {
    return m_currentState;
}

int TestableBlackjackGame::getCurrentRound() {
    return m_currentRound;
}

bool TestableBlackjackGame::getPlayerStayed() {
    return m_playerStayed;
}

bool TestableBlackjackGame::getHouseStayed() {
    return m_houseStayed;
}

BlackjackGame::EndCondition TestableBlackjackGame::getEndCondition() {
    return m_endCondition;
}

Spot TestableBlackjackGame::getDeck() {
    return m_deck;
}

Spot TestableBlackjackGame::getPlayerHand() {
    return m_playerHand;
}

Spot TestableBlackjackGame::getHouseHand() {
    return m_houseHand;
}

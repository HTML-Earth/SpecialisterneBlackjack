//
// Created by Stefan on 17-Sep-26.
//

#include "BlackjackGame.h"

#include "CardManager.h"

BlackjackGame::BlackjackGame() {
    m_deck = Spot {};
    m_playerHand = Spot {};
    m_houseHand = Spot {};
}

void BlackjackGame::performHouseTurn() {
    //TODO: choose between hit and stay
    CardManager::drawCard(m_deck,m_houseHand);
}

void BlackjackGame::checkWinner() {
    int playerScore = m_playerHand.getCombinedValue();
    int houseScore = m_houseHand.getCombinedValue();

    //TODO: proper victory/defeat
    if (playerScore == 21) {
        //victory
    }
}

void BlackjackGame::startGame() {
    // Reset
    m_deck.clear();
    m_playerHand.clear();
    m_houseHand.clear();

    // Create new deck of cards
    auto deck = CardManager::createDeck();
    for (auto card: deck) {
        m_deck.addCard(*card);
    }

    // Draw 2 cards for each player
    for (int i = 0; i < 2; i++) {
        CardManager::drawCard(m_deck,m_playerHand);
        CardManager::drawCard(m_deck,m_houseHand);
    }
}

void BlackjackGame::hit() {
    CardManager::drawCard(m_deck,m_playerHand);
    performHouseTurn();
    checkWinner();
}

void BlackjackGame::stay() {
    performHouseTurn();
    checkWinner();
}

std::string BlackjackGame::gameStatus() {
    //TODO: show player and house cards, victory/defeat, hit/stay options etc.
    return "Your cards: _";
}

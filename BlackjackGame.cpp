//
// Created by Stefan on 17-Sep-26.
//

#include "BlackjackGame.h"

#include "CardManager.h"

using namespace std;

BlackjackGame::BlackjackGame() {
    m_currentState = inactive;
    m_playerStayed = false;
    m_houseStayed = false;
    m_endCondition = none;
    m_deck = Spot {};
    m_playerHand = Spot {};
    m_houseHand = Spot {};
}

void BlackjackGame::performHouseTurn() {
    //TODO: choose between hit and stay
    CardManager::drawCard(m_deck,m_houseHand);
    checkWinner();
}

void BlackjackGame::checkWinner() {
    int playerScore = m_playerHand.getCombinedValue();
    int houseScore = m_houseHand.getCombinedValue();

    if (playerScore > 21) {
        endGame(houseWon);
    }
    if (houseScore > 21) {
        endGame(playerWon);
    }

    bool finalCheck = m_playerStayed && m_houseStayed;
    if (not finalCheck) {
        // Don't declare winner yet
        return;
    }

    int playerDelta = 21 - playerScore;
    int houseDelta = 21 - houseScore;
    if (playerDelta == houseDelta) {
        endGame(tied);
    }
    else {
        if (playerDelta < houseDelta) {
            endGame(playerWon);
        }
        else {
            endGame(houseWon);
        }
    }
}

void BlackjackGame::endGame(EndCondition condition) {
    m_currentState = ended;
    m_endCondition = condition;
}

void BlackjackGame::startGame() {
    // Reset
    m_currentState = playing;
    m_playerStayed = false;
    m_houseStayed = false;
    m_endCondition = none;
    m_deck.clear();
    m_playerHand.clear();
    m_houseHand.clear();

    // Create new deck of cards and shuffle it
    auto deck = CardManager::createDeck();
    for (auto card: deck) {
        m_deck.addCard(*card);
    }
    m_deck.shuffleCards();

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
    m_playerStayed = true;
    performHouseTurn();
    checkWinner();
}

string BlackjackGame::gameStatus() {
    string output;
    switch (m_currentState) {
        case inactive:
            output = "Game has not started yet.";
            break;
        case playing:
            output += "Your cards:\n";
            for (auto card: m_playerHand.getCards()) {
                output += card->getCardName();
                output += "\n";
            }
            output += "Type hit or stay to continue...";
            break;
        case ended:
            switch (m_endCondition) {
                case none:
                    throw "Game ended without end condition";
                case playerWon:
                    output = "You won!";
                    break;
                case houseWon:
                    output = "The house won.";
                    break;
                case tied:
                    output = "You tied with the house.";
                    break;
            }
            break;
        default:
            throw "Invalid game state";
    }
    return output;
}

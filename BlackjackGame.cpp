//
// Created by Stefan on 17-Sep-26.
//

#include "BlackjackGame.h"

#include "CardManager.h"

using namespace std;

void BlackjackGame::performHouseTurn() {
    if (m_currentState != playing && m_currentState != waitingForComputer)
        return;

    if (m_houseHand.getCombinedValue() < 17) {
        CardManager::drawCard(m_deck,m_houseHand);
        checkWinner();
    }
    else {
        m_houseStayed = true;
        checkWinner();
    }
    m_currentRound++;
}

void BlackjackGame::checkWinner() {
    if (m_currentState != playing && m_currentState != waitingForComputer)
        return;

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
    if (m_currentState != playing && m_currentState != waitingForComputer)
        return;

    m_currentState = ended;
    m_endCondition = condition;
}

string BlackjackGame::printCardsInSpot(Spot& spot, bool hideFirstCard) {
    string output;
    bool firstCard = true;
    for (auto card: spot.getCards()) {
        if (firstCard) {
            firstCard = false;
            if (hideFirstCard) {
                if (m_shortOutputIsEnabled)
                    output += "??";
                else
                    output += "??? of ???";
                continue;
            }
        }
        else
            output += ", ";
        output += card->getCardName(m_shortOutputIsEnabled);
    }
    return output;
}

std::string BlackjackGame::printCurrentHands() {
    string output;

    output += "\tYOU:\n";
    output += '\t';
    output += '(';
    output += to_string(m_playerHand.getCombinedValue());
    output += ") ";
    output += '\t';
    output += printCardsInSpot(m_playerHand, false);
    output += '\n';

    output += "\tHOUSE:\n";
    output += '\t';
    if (m_currentState == ended) {
        output += '(';
        output += to_string(m_houseHand.getCombinedValue());
        output += ") ";
    }
    else {
        output += "(???) ";
    }
    output += '\t';
    output += printCardsInSpot(m_houseHand, m_currentState == playing);

    return output;
}

string BlackjackGame::printGameStatus() {
    string output;
    switch (m_currentState) {
        case inactive:
            output = "Game has not started yet.";
            break;
        case playing:
            output += "ROUND ";
            output += to_string(m_currentRound);
            output += ":\n";

            output += printCurrentHands();
            output += "\n\n";

            output += "Type 'hit' or 'stand' to continue...";
            break;
        case waitingForComputer:
            performHouseTurn();
            output = printGameStatus();
            break;
        case ended:
            switch (m_endCondition) {
                case none:
                    throw "Game ended without end condition";
                case playerWon:
                    output = "== YOU WON! ==\n";
                    break;
                case houseWon:
                    output = "== The house won. ==\n";
                    break;
                case tied:
                    output = "== You tied with the house. ==\n";
                    break;
            }
            output += printCurrentHands();
            output += "\n\n";
            output += "Type 'start' to play again or 'quit' to stop the application...";
            break;
        default:
            throw "Invalid game state";
    }
    return output;
}

BlackjackGame::BlackjackGame() {
    m_currentState = inactive;
    m_currentRound = 0;
    m_playerStayed = false;
    m_houseStayed = false;
    m_endCondition = none;
    m_deck = Spot {};
    m_playerHand = Spot {};
    m_houseHand = Spot {};
}

std::string BlackjackGame::startGame() {
    // Reset
    m_currentState = playing;
    m_currentRound = 1;
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

    return printGameStatus();
}

std::string BlackjackGame::hit() {
    if (m_currentState != playing)
        return "Game is not active. Type 'start' first.";

    CardManager::drawCard(m_deck,m_playerHand);
    checkWinner();
    performHouseTurn();

    return printGameStatus();
}

std::string BlackjackGame::stand() {
    if (m_currentState != playing)
        return "Game is not active. Type 'start' first.";

    m_playerStayed = true;
    m_currentState = waitingForComputer;
    performHouseTurn();

    return printGameStatus();
}

std::string BlackjackGame::toggleShort() {
    m_shortOutputIsEnabled = !m_shortOutputIsEnabled;

    if (m_shortOutputIsEnabled)
        return "Short output enabled.";
    else
        return "Short output disabled.";
}

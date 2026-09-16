//
// Created by Stefan on 16-Sep-26.
//

#include "AceCard.h"

#include <iostream>
using namespace std;

AceCard::AceCard(Suit suit) {
    m_suit = suit;
}

int AceCard::getValue(vector<Card*> otherCards) {
    int existingSum = 0;
    for (auto card: otherCards) {
        existingSum += card->getValue(vector<Card*>{}); //TODO: recursive check
    }
    if (existingSum + 11 > 21)
        return 1;
    else
        return 11;
}

string AceCard::getCardName() {
    string suitName = Card::getSuitName(m_suit);
    return "Ace of " + suitName;
}
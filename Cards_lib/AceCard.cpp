//
// Created by Stefan on 16-Sep-26.
//

#include "AceCard.h"

#include <iostream>
using namespace std;

AceCard::AceCard(Suit suit) {
    m_suit = suit;
}

int AceCard::getValue(int existingValue) {
    if (existingValue + 11 > 21)
        return 1;
    else
        return 11;
}

string AceCard::getCardName(bool useShortVersion) {
    if (useShortVersion) {
        string suitIcon = Card::getSuitIcon(m_suit);
        return "A" + suitIcon;
    }
    else {
        string suitName = Card::getSuitName(m_suit);
        return "Ace of " + suitName;
    }
}
//
// Created by Stefan on 16-Sep-26.
//

#include "AceCard.h"
using namespace std;

AceCard::AceCard(Suit suit) {
    m_suit = suit;
}

int AceCard::getValue() {
    //TODO: return 11 when possible
    return 1;
}

string AceCard::getCardName() {
    string suitName = Card::getSuitName(m_suit);
    return "Ace of " + suitName;
}
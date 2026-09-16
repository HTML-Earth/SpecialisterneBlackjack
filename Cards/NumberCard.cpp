//
// Created by Stefan on 16-Sep-26.
//

#include "NumberCard.h"
using namespace std;

NumberCard::NumberCard(Suit suit, int number) {
    m_suit = suit;
    m_number = number;
}

int NumberCard::getValue() {
    return m_number;
}

string NumberCard::getCardName() {
    string number = to_string(m_number);
    string suitName = Card::getSuitName(m_suit);
    return number + " of " + suitName;
}
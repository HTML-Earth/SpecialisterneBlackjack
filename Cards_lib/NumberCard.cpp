//
// Created by Stefan on 16-Sep-26.
//

#include "NumberCard.h"
using namespace std;

NumberCard::NumberCard(Suit suit, int number) {
    if (number < 2) {
        throw "NumberCard can not be less than 2";
    }
    if (number > 10) {
        throw "NumberCard can not be greater than 10";
    }
    m_suit = suit;
    m_number = number;
}

int NumberCard::getValue(int) {
    return m_number;
}

string NumberCard::getCardName(bool useShortVersion) {
    string number = to_string(m_number);
    if (useShortVersion) {
        string suitIcon = Card::getSuitIcon(m_suit);
        return number + suitIcon;
    }
    else {
        string suitName = Card::getSuitName(m_suit);
        return number + " of " + suitName;
    }
}
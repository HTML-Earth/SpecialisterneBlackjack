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

int NumberCard::getValue(vector<Card*>) {
    return m_number;
}

string NumberCard::getCardName() {
    string number = to_string(m_number);
    string suitName = Card::getSuitName(m_suit);
    return number + " of " + suitName;
}
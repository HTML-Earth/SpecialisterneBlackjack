//
// Created by Stefan on 16-Sep-26.
//

#include "FaceCard.h"
using namespace std;

FaceCard::FaceCard(Suit suit, Character character) {
    m_suit = suit;
    m_character = character;
}

int FaceCard::getValue() {
    return 10;
}

string FaceCard::getCardName() {
    string characterName = FaceCard::getCharacterName(m_character);
    string suitName = Card::getSuitName(m_suit);
    return characterName + " of " + suitName;
}
//
// Created by Stefan on 16-Sep-26.
//

#include "FaceCard.h"
using namespace std;

FaceCard::FaceCard(Suit suit, Character character) {
    m_suit = suit;
    m_character = character;
}

int FaceCard::getValue(int) {
    return 10;
}

string FaceCard::getCardName(bool useShortVersion) {
    if (useShortVersion) {
        string characterLetter = FaceCard::getCharacterLetter(m_character);
        string suitIcon = Card::getSuitIcon(m_suit);
        return characterLetter + suitIcon;
    }
    else {
        string characterName = FaceCard::getCharacterName(m_character);
        string suitName = Card::getSuitName(m_suit);
        return characterName + " of " + suitName;
    }
}
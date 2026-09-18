//
// Created by Stefan on 16-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_FACECARD_H
#define SPECIALISTERNEBLACKJACK_FACECARD_H

#include "Card.h"


class FaceCard : public Card {
public:
    enum Character {
        jack,
        queen,
        king
    };
    static std::string getCharacterName(Character character) {
        switch (character) {
            case jack:
                return "Jack";
            case queen:
                return "Queen";
            case king:
                return "King";
            default:
                return "Errors";
        }
    }
    static std::string getCharacterLetter(Character character) {
        switch (character) {
            case jack:
                return "J";
            case queen:
                return "Q";
            case king:
                return "K";
            default:
                return "E";
        }
    }
private:
    Character m_character;
public:
    FaceCard(Suit suit, Character character);

    int getValue(int existingValue) override;
    std::string getCardName(bool useShortVersion) override;
};


#endif //SPECIALISTERNEBLACKJACK_FACECARD_H

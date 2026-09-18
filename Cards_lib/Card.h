//
// Created by Stefan on 16-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_CARD_H
#define SPECIALISTERNEBLACKJACK_CARD_H
#include <string>


class Card {
public:
    enum Suit {
        hearts,
        diamonds,
        spades,
        clubs
    };
    static std::string getSuitName(Suit suit) {
        switch (suit) {
            case hearts:
                return "Hearts";
            case diamonds:
                return "Diamonds";
            case spades:
                return "Spades";
            case clubs:
                return "Clubs";
            default:
                return "Errors";
        }
    }
    static std::string getSuitIcon(Suit suit) {
        switch (suit) {
            case hearts:
                return "♥";
            case diamonds:
                return "♦";
            case spades:
                return "♠";
            case clubs:
                return "♣";
            default:
                return "!";
        }
    }
protected:
    Suit m_suit;
public:
    virtual int getValue(int existingValue) = 0;
    virtual std::string getCardName(bool useShortVersion) = 0;
};


#endif //SPECIALISTERNEBLACKJACK_CARD_H

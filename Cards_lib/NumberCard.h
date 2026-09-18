//
// Created by Stefan on 16-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_NUMBERCARD_H
#define SPECIALISTERNEBLACKJACK_NUMBERCARD_H

#include "Card.h"


class NumberCard : public Card {
    int m_number;
public:
    NumberCard(Suit suit, int number);

    int getValue(int existingValue) override;
    std::string getCardName(bool useShortVersion) override;
};


#endif //SPECIALISTERNEBLACKJACK_NUMBERCARD_H

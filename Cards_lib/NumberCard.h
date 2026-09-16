//
// Created by Stefan on 16-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_NUMBERCARD_H
#define SPECIALISTERNEBLACKJACK_NUMBERCARD_H
#include <vector>

#include "Card.h"


class NumberCard : public Card {
    int m_number;
public:
    NumberCard(Suit suit, int number);

    int getValue(std::vector<Card*> otherCards) override;
    std::string getCardName() override;
};


#endif //SPECIALISTERNEBLACKJACK_NUMBERCARD_H

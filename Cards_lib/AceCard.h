//
// Created by Stefan on 16-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_ACECARD_H
#define SPECIALISTERNEBLACKJACK_ACECARD_H
#include <vector>

#include "Card.h"


class AceCard : public Card {
public:
    AceCard(Suit suit);

    int getValue(int existingValue) override;
    std::string getCardName() override;
};


#endif //SPECIALISTERNEBLACKJACK_ACECARD_H

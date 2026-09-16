//
// Created by Stefan on 16-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_SPOT_H
#define SPECIALISTERNEBLACKJACK_SPOT_H
#include <vector>

#include "Card.h"


class Spot {
private:
    std::vector<Card*> m_cards;
public:
    Spot();

    std::vector<Card*> getCards();
    void addCard(Card &card);
    void shuffleCards();
    Card& removeTopCard();
};


#endif //SPECIALISTERNEBLACKJACK_SPOT_H

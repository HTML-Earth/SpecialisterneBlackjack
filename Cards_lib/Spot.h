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
    int getCombinedValue();
    void addCard(Card &card);
    void shuffleCards();
    Card& removeTopCard();
    void clear();
};


#endif //SPECIALISTERNEBLACKJACK_SPOT_H

//
// Created by Stefan on 16-Sep-26.
//

#ifndef SPECIALISTERNEBLACKJACK_CARDMANAGER_H
#define SPECIALISTERNEBLACKJACK_CARDMANAGER_H
#include <vector>

#include "Card.h"


class CardManager {
public:
    static std::vector<Card*> createDeck();
};


#endif //SPECIALISTERNEBLACKJACK_CARDMANAGER_H

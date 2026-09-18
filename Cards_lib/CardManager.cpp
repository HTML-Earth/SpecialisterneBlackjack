//
// Created by Stefan on 16-Sep-26.
//

#include "CardManager.h"

#include <vector>

#include "AceCard.h"
#include "Card.h"
#include "FaceCard.h"
#include "NumberCard.h"

using namespace std;

vector<Card*> CardManager::createDeck() {
    vector<Card*> cards;
    for (int s = 0; s < 4; s++) {
        auto suit = static_cast<Card::Suit>(s);

        auto ace = new AceCard(suit);
        cards.emplace_back(ace);

        for (int i = 2; i <= 10; i++) {
            auto card = new NumberCard(suit, i);
            cards.emplace_back(card);
        }

        auto jack = new FaceCard(suit, FaceCard::jack);
        cards.emplace_back(jack);
        auto queen = new FaceCard(suit, FaceCard::queen);
        cards.emplace_back(queen);
        auto king = new FaceCard(suit, FaceCard::king);
        cards.emplace_back(king);
    }
    return cards;
}

void CardManager::drawCard(Spot& from, Spot& to) {
    to.addCard(from.removeTopCard());
}

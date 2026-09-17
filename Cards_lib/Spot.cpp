//
// Created by Stefan on 16-Sep-26.
//

#include "Spot.h"

#include <algorithm>
#include <random>
#include <vector>

#include "Card.h"

using namespace std;

Spot::Spot() {
    m_cards = vector<Card*> {};
}

vector<Card *> Spot::getCards() {
    return m_cards;
}

int Spot::getCombinedValue() {
    int sum = 0;
    for (auto card: m_cards) {
        sum += card->getValue(sum);
    }
    return sum;
}

void Spot::addCard(Card &card) {
    m_cards.emplace_back(&card);
}

void Spot::shuffleCards() {
    shuffle(m_cards.begin(), m_cards.end(), std::mt19937(std::random_device()()));
}

Card & Spot::removeTopCard() {
    auto card = m_cards.back();
    m_cards.pop_back();
    return *card;
}

void Spot::clear() {
    m_cards.clear();
}

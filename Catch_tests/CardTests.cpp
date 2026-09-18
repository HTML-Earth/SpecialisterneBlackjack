//
// Created by Stefan on 14-Sep-26.
//

#include <iostream>
#include <vector>

#include <catch2/catch_test_macros.hpp>

#include "Card.h"
#include "AceCard.h"
#include "FaceCard.h"
#include "NumberCard.h"
#include "CardManager.h"

using namespace std;

static vector<string> allCardNames {
    "Ace of Hearts",
    "2 of Hearts",
    "3 of Hearts",
    "4 of Hearts",
    "5 of Hearts",
    "6 of Hearts",
    "7 of Hearts",
    "8 of Hearts",
    "9 of Hearts",
    "10 of Hearts",
    "Jack of Hearts",
    "Queen of Hearts",
    "King of Hearts",
    "Ace of Diamonds",
    "2 of Diamonds",
    "3 of Diamonds",
    "4 of Diamonds",
    "5 of Diamonds",
    "6 of Diamonds",
    "7 of Diamonds",
    "8 of Diamonds",
    "9 of Diamonds",
    "10 of Diamonds",
    "Jack of Diamonds",
    "Queen of Diamonds",
    "King of Diamonds",
    "Ace of Spades",
    "2 of Spades",
    "3 of Spades",
    "4 of Spades",
    "5 of Spades",
    "6 of Spades",
    "7 of Spades",
    "8 of Spades",
    "9 of Spades",
    "10 of Spades",
    "Jack of Spades",
    "Queen of Spades",
    "King of Spades",
    "Ace of Clubs",
    "2 of Clubs",
    "3 of Clubs",
    "4 of Clubs",
    "5 of Clubs",
    "6 of Clubs",
    "7 of Clubs",
    "8 of Clubs",
    "9 of Clubs",
    "10 of Clubs",
    "Jack of Clubs",
    "Queen of Clubs",
    "King of Clubs"
};

TEST_CASE( "All cards exist in deck", "[cards]" ) {
    auto fullDeck = CardManager::createDeck();
    for (auto& cardName: allCardNames) {
        bool existsInDeck = false;
        for (auto card: fullDeck) {
            auto name = card->getCardName(false);
            if (name == cardName) {
                existsInDeck = true;
                break;
            }
        }
        INFO(cardName);
        REQUIRE(existsInDeck);
    }
}

TEST_CASE( "Card amount is correct", "[cards]" ) {
    auto fullDeck = CardManager::createDeck();
    REQUIRE(fullDeck.size() == 52);
}

TEST_CASE( "The value of cards 2 to 10 are the same as their number", "[cards]" ) {
    for (int s = 0; s < 4; s++) {
        auto suit = static_cast<Card::Suit>(s);
        for (int i = 2; i <= 10; i++) {
            auto card = new NumberCard(suit, i);
            INFO(card->getCardName(false));
            REQUIRE(card->getValue(0) == i);
        }
    }
}

TEST_CASE( "The value of an ace depends on the potential sum of the deck", "[cards]" ) {
    for (int s = 0; s < 4; s++) {
        auto suit = static_cast<Card::Suit>(s);

        auto ace = new AceCard(suit);

        for (int i = 0; i <= 10; i++) {
            SECTION("sum is " + to_string(i) + "; expect value 11") {
                CHECK(ace->getValue(i) == 11);
            }
        }

        for (int i = 11; i < 100; i++) {
            SECTION("sum is " + to_string(i) + "; expect value 1") {
                CHECK(ace->getValue(i) == 1);
            }
        }
    }

}

TEST_CASE( "The value of a jack, queen or king is 10", "[cards]" ) {
    for (int s = 0; s < 4; s++) {
        auto suit = static_cast<Card::Suit>(s);

        auto jack = new FaceCard(suit, FaceCard::jack);
        INFO(jack->getCardName(false));
        REQUIRE(jack->getValue(0) == 10);

        auto queen = new FaceCard(suit, FaceCard::queen);
        INFO(queen->getCardName(false));
        REQUIRE(queen->getValue(0) == 10);

        auto king = new FaceCard(suit, FaceCard::king);
        INFO(king->getCardName(false));
        REQUIRE(king->getValue(0) == 10);
    }
}

TEST_CASE( "Number cards cannot be less than 2 or greater than 10", "[cards]" ) {
    for (int s = 0; s < 4; s++) {
        auto suit = static_cast<Card::Suit>(s);
        for (int i = -100; i <= 1; i++) {
            INFO(to_string(i) + " of " + Card::getSuitName(suit));
            REQUIRE_THROWS(new NumberCard(suit, i));
        }
        for (int i = 11; i <= 100; i++) {
            INFO(to_string(i) + " of " + Card::getSuitName(suit));
            REQUIRE_THROWS(new NumberCard(suit, i));
        }
    }
}
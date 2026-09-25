//
// Created by Stefan on 17-Sep-26.
//

#include <catch2/catch_test_macros.hpp>

#include "TestableBlackjackGame.h"
#include "../BlackjackGame.h"

TEST_CASE("Game starts properly", "[blackjack]") {
    auto game = new TestableBlackjackGame();
    REQUIRE_NOTHROW(game->startGame());
    REQUIRE(game->getCurrentRound() == 1);
    REQUIRE(game->getCurrentState() == BlackjackGame::playing);
    REQUIRE(game->getEndCondition() == BlackjackGame::none);
    REQUIRE(game->getPlayerStayed() == false);
    REQUIRE(game->getHouseStayed() == false);
    REQUIRE(game->getDeck().getCards().size() == 52 - 2 - 2);
    REQUIRE(game->getPlayerHand().getCards().size() == 2);
    REQUIRE(game->getHouseHand().getCards().size() == 2);
}

TEST_CASE("Game will end after standing", "[blackjack]") {
    for (int i = 0; i < 100; i++) {
        auto game = new TestableBlackjackGame();
        REQUIRE_NOTHROW(game->startGame());
        REQUIRE_NOTHROW(game->stand());

        REQUIRE(game->getCurrentState() == BlackjackGame::ended);
    }
}

TEST_CASE("Game will have ended after drawing ten cards", "[blackjack]") {
    for (int i = 0; i < 100; i++) {
        auto game = new TestableBlackjackGame();
        REQUIRE_NOTHROW(game->startGame());
        for (int c = 0; c < 10; c++) {
            REQUIRE_NOTHROW(game->hit());
        }
        REQUIRE(game->getCurrentState() == BlackjackGame::ended);
    }
}

TEST_CASE("Hit draws card", "[blackjack]") {
    auto game = new TestableBlackjackGame();
    REQUIRE_NOTHROW(game->startGame());
    REQUIRE(game->getPlayerStayed() == false);
    REQUIRE(game->getPlayerHand().getCards().size() == 2);
    REQUIRE_NOTHROW(game->hit());
    REQUIRE(game->getPlayerStayed() == false);
    REQUIRE(game->getPlayerHand().getCards().size() == 3);
}

TEST_CASE("Stand does not draw card", "[blackjack]") {
    auto game = new TestableBlackjackGame();
    REQUIRE_NOTHROW(game->startGame());
    REQUIRE(game->getPlayerStayed() == false);
    REQUIRE(game->getPlayerHand().getCards().size() == 2);
    REQUIRE_NOTHROW(game->stand());
    REQUIRE(game->getPlayerStayed() == true);
    REQUIRE(game->getPlayerHand().getCards().size() == 2);
}

TEST_CASE("Can't hit when game is inactive", "[blackjack]") {
    auto game = new TestableBlackjackGame();
    REQUIRE(game->getPlayerHand().getCards().size() == 0);
    REQUIRE_NOTHROW(game->hit());
    REQUIRE(game->getPlayerHand().getCards().size() == 0);
}

TEST_CASE("Can't stand when game is inactive", "[blackjack]") {
    auto game = new TestableBlackjackGame();
    REQUIRE(game->getPlayerStayed() == false);
    REQUIRE_NOTHROW(game->stand());
    REQUIRE(game->getPlayerStayed() == false);
}
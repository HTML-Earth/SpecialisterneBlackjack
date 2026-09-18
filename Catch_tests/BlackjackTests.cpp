//
// Created by Stefan on 17-Sep-26.
//

#include <catch2/catch_test_macros.hpp>

#include "CardManager.h"
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

TEST_CASE("Hit draws card", "[blackjack]") {
    auto game = new TestableBlackjackGame();
    REQUIRE_NOTHROW(game->startGame());
    REQUIRE_NOTHROW(game->hit());
    REQUIRE(game->getPlayerStayed() == false);
    REQUIRE(game->getPlayerHand().getCards().size() == 3);
}

TEST_CASE("Stand does not draw card", "[blackjack]") {
    auto game = new TestableBlackjackGame();
    REQUIRE_NOTHROW(game->startGame());
    REQUIRE_NOTHROW(game->stand());
    REQUIRE(game->getPlayerStayed() == true);
    REQUIRE(game->getPlayerHand().getCards().size() == 2);
}
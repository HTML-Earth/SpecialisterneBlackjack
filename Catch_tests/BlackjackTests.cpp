//
// Created by Stefan on 17-Sep-26.
//

#include <catch2/catch_test_macros.hpp>

#include "CardManager.h"
#include "../BlackjackGame.h"

TEST_CASE("Game starts without exceptions", "[blackjack]") {
    auto game = new BlackjackGame();
    REQUIRE_NOTHROW(game->startGame());
    REQUIRE_NOTHROW(game->printGameStatus());
}
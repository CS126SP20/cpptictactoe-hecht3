// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <string>

#include <catch2/catch.hpp>
#include <tictactoe/tictactoe.h>


using tictactoe::EvaluateBoard;
using tictactoe::TicTacToeState;

TEST_CASE("No winner", "[no-winner]") {
  REQUIRE(EvaluateBoard("xxoooxxxo") == TicTacToeState::NoWinner);
}

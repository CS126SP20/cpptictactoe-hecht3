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


TEST_CASE("Board too small", "[invalid-input]") {
    REQUIRE(EvaluateBoard(".......X") == TicTacToeState::InvalidInput);
}

TEST_CASE("boardTooLarge", "[]") {
    REQUIRE(EvaluateBoard(".......X..") == TicTacToeState::InvalidInput);
}

//The following are all the tests for UnreachableState boards
TEST_CASE("Too many Xs with X horizontal winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("XO.XXX.O.") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Xs with X vertical winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("XO.X.XXOX") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Xs with X diagonal winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("XO..XX.OX") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Os with X horizontal winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard(".O.XXX.OO") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Os with X vertical winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("XOOXOXX.O") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Os with X diagonal winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("XOOOXX.OX") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Xs without winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard(".XX.lmn..") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Os with O horizontal winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard(".X.OOO..X") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Os with O vertical winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("OX.O..OX.") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Os withO diagonal winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("OX..O..XO") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Xs with O horizontal winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("XX.OOO.XX") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Xs with O vertical winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("OXXXXOOX.") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Xs with O diagonal winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("OX..OXXXO") == TicTacToeState::UnreachableState);
}

TEST_CASE("Too many Os without winner", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("..O......") == TicTacToeState::UnreachableState);
}

TEST_CASE("two winners", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("OOOXXX...") == TicTacToeState::UnreachableState);
}

//The following are all the tests for noWinner boards
TEST_CASE("simple no winner board", "no-winner") {
    REQUIRE(EvaluateBoard("O...X.X..") == TicTacToeState::NoWinner);
}

TEST_CASE("tie game board", "no-winner") {
    REQUIRE(EvaluateBoard("OXOXOXXOX") == TicTacToeState::NoWinner);
}

TEST_CASE("empty board", "no-winner") {
    REQUIRE(EvaluateBoard("mmmm\n\n\n\n\n") == TicTacToeState::NoWinner);
}

//The following are all the tests for winner boards
//Xwins:
TEST_CASE("X wins row 1", "[x-wins]") {
    REQUIRE(EvaluateBoard("XXXOO.$$$") == TicTacToeState::Xwins);
}

TEST_CASE("X wins row 2", "[x-wins]") {
    REQUIRE(EvaluateBoard("OO.XXX...") == TicTacToeState::Xwins);
}

TEST_CASE("X wins row 3", "[x-wins]") {
    REQUIRE(EvaluateBoard("OO....XXX") == TicTacToeState::Xwins);
}

TEST_CASE("X wins col 1", "[x-wins]") {
    REQUIRE(EvaluateBoard("XOOX..X..") == TicTacToeState::Xwins);
}

TEST_CASE("X wins col 2", "[x-wins]") {
    REQUIRE(EvaluateBoard("OXO.X..X.") == TicTacToeState::Xwins);
}

TEST_CASE("X wins col 3", "[x-wins]") {
    REQUIRE(EvaluateBoard("OOX..X..X") == TicTacToeState::Xwins);
}

TEST_CASE("X wins diagonal 1", "[x-wins]") {
    REQUIRE(EvaluateBoard("XO..X.O.X") == TicTacToeState::Xwins);
}

TEST_CASE("X wins diagonal 2", "[x-wins]") {
    REQUIRE(EvaluateBoard("O.X.X.X.O") == TicTacToeState::Xwins);
}

TEST_CASE("X wins full board", "[x-wins]") {
    REQUIRE(EvaluateBoard("XOXOXXXOO") == TicTacToeState::Xwins);
}

TEST_CASE
("X wins diagonal and vertical", "[x-wins]") {
    REQUIRE(EvaluateBoard("XOXOXXOOX") == TicTacToeState::Xwins);
}

TEST_CASE("X wins vertical and horizontal", "[x-wins]") {
    REQUIRE(EvaluateBoard("XXXOXOOXO") == TicTacToeState::Xwins);
}
//Owins
TEST_CASE("O wins row 1", "[o-wins]") {
    REQUIRE(EvaluateBoard("OOOXX...X") == TicTacToeState::Owins);
}

TEST_CASE("O wins row 2", "[o-wins]") {
    REQUIRE(EvaluateBoard("XX.OOO..X") == TicTacToeState::Owins);
}

TEST_CASE("O wins row 3", "[o-wins]") {
    REQUIRE(EvaluateBoard("XX.X..OOO") == TicTacToeState::Owins);
}

TEST_CASE("O wins col 1", "[o-wins]") {
    REQUIRE(EvaluateBoard("OXXO..O.X") == TicTacToeState::Owins);
}

TEST_CASE("O wins col 2", "[o-wins]") {
    REQUIRE(EvaluateBoard("XOXXO..O.") == TicTacToeState::Owins);
}

TEST_CASE("O wins col 3", "[o-wins]") {
    REQUIRE(EvaluateBoard("XXO..O.XO") == TicTacToeState::Owins);
}

TEST_CASE("O wins diagonal 1", "[o-wins]") {
    REQUIRE(EvaluateBoard("OX..O.XXO") == TicTacToeState::Owins);
}

TEST_CASE("O wins diagonal 2", "[o-wins]") {
    REQUIRE(EvaluateBoard("X.O.O.OXX") == TicTacToeState::Owins);
}
//O winning a full board is actually not possible since X goes first and there are an odd number of squares.
TEST_CASE("O wins almost full board", "[o-wins]") {
    REQUIRE(EvaluateBoard("OXXXOX.OO") == TicTacToeState::Owins);
}
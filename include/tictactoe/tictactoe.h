// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef CPPTICTACTOE_TICTACTOE_H_
#define CPPTICTACTOE_TICTACTOE_H_

#include <string>


namespace tictactoe {

// Represents the states of a tictactoe game.
enum class TicTacToeState {
  UnreachableState,
  Xwins,
  Owins,
  NoWinner,
  InvalidInput,
};

// Returns the corresponding state of the board.
TicTacToeState EvaluateBoard(const std::string& board);
// Counts the number of characters for each player in the board
int CharacterCounter(std::string board, char letter);
// Creates arrays that represent the positions of the players on the board
void InitializePositionArrays(std::string board);
// Checks how many wins each player has on the board
int CheckWins(std::string board, int winPossibilities[][3]); //////Change this 3

}  // namespace tictactoe

#endif  // CPPTICTACTOE_TICTACTOE_H_


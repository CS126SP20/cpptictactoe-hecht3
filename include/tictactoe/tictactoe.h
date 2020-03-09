// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef CPPTICTACTOE_TICTACTOE_H_
#define CPPTICTACTOE_TICTACTOE_H_

#include <string>
#include <vector>


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
    TicTacToeState EvaluateBoard(const std::string& board_state);

}  // namespace tictactoe

#endif  // CPPTICTACTOE_TICTACTOE_H_


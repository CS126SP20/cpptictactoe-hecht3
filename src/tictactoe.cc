// Copyright 2020 Connell Hecht. All rights reserved.

#include <set>
#include <string>

#include <tictactoe/tictactoe.h>
#include <algorithm>


namespace tictactoe {

    using std::string;

    const int kBoardSize = 9;
    const int kTwoDirections = 2;
    const int kMaxXs = 5;
    const int kMaxOs = 4;
    const int kThreeInARow = 3;
    const int kTypesOfRowOrColWins = 3;
    const int kTypesOfDiagWins = 2;

    const int kPositionOne = 1;
    const int kPositionTwo = 2;
    const int kPositionThree = 3;
    const int kPositionFour = 4;
    const int kPositionFive = 5;
    const int kPositionSix = 6;
    const int kPositionSeven = 7;
    const int kPositionEight = 8;
    const int kPositionNine = 9;

    int XWinCounter;
    int OWinCounter;
    int XPositions[kBoardSize];
    int OPositions[kBoardSize];

    TicTacToeState EvaluateBoard(const string& board) {
        if (board.length() != kBoardSize) {
            return TicTacToeState::InvalidInput;
        }
        XWinCounter = 0;
        OWinCounter = 0;

        // Make the whole board lowercase
        // The following for loop is from https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/
        std::for_each(board.begin(), board.end(), [](char & c) {
            c = ::tolower(c);
        });

        int XCount = CharacterCounter(board, 'x');
        int OCount = CharacterCounter(board, 'o');
        if (OCount > XCount || XCount - 1 > OCount) {
            return TicTacToeState::UnreachableState;
        }

        InitializePositionArrays(board);

        int rowWinPossibilities[kTypesOfRowOrColWins][kThreeInARow] =
                {{kPositionOne, kPositionTwo, kPositionThree},
                 {kPositionFour, kPositionFive, kPositionSix},
                 {kPositionSeven, kPositionEight, kPositionNine}};
        int colWinPossibilities[kTypesOfRowOrColWins][kThreeInARow] =
                {{kPositionOne, kPositionFour, kPositionSeven},
                 {kPositionTwo, kPositionFive, kPositionEight},
                 {kPositionThree, kPositionSix, kPositionNine}};
        int diagWinPossibilities[kTypesOfDiagWins][kThreeInARow] =
                {{kPositionOne, kPositionFive, kPositionNine},
                 {kPositionThree, kPositionFive, kPositionSeven}};

        CheckWins(board, rowWinPossibilities);
        CheckWins(board, colWinPossibilities);
        CheckWins(board, diagWinPossibilities);

        if ((OWinCounter > 1)
            || (OWinCounter == 1 && XWinCounter == 1)
            || (OWinCounter == 1 && XCount > OCount)
            || (XWinCounter == 1 && OCount == XCount)) {
            return TicTacToeState::UnreachableState;
        } else if (    XWinCounter == 1
                       || (XWinCounter == 2 && XCount == 5 && OCount == 4)) {
            return TicTacToeState::Xwins;
        } else if (OWinCounter == 1) {
            return TicTacToeState::Owins;
        }
        return TicTacToeState::NoWinner;

    }

    int CharacterCounter(std::string board, char letter) {

    }

    void InitializePositionArrays(std::string board) {

    }

    int CheckWins(std::string board, int winPossibilities[][kThreeInARow]) {

    }

}  // namespace tictactoe

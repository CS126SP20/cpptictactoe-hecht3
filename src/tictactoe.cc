// Copyright 2020 Connell Hecht. All rights reserved.

#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#include <tictactoe/tictactoe.h>


namespace tictactoe {

    using std::string;
    using namespace std;

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

    TicTacToeState EvaluateBoard(const string boardState) {
        string board = boardState;
        if (board.length() != kBoardSize) {
            return TicTacToeState::InvalidInput;
        }
        XWinCounter = 0;
        OWinCounter = 0;

        // Make the whole board lowercase
        // The following line is from https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
        transform(board.begin(), board.end(), board.begin(), ::tolower);

        int XCount = CharacterCounter(board, 'x');
        int OCount = CharacterCounter(board, 'o');
        if (OCount > XCount || XCount - 1 > OCount) {
            return TicTacToeState::UnreachableState;
        }

        InitializePositionArrays(board);
        vector<vector<int>> rowWinPossibilities
                {{kPositionOne,   kPositionTwo,   kPositionThree},
                 {kPositionFour,  kPositionFive,  kPositionSix},
                 {kPositionSeven, kPositionEight, kPositionNine}};
        vector<vector<int>> colWinPossibilities
                {{kPositionOne,   kPositionFour, kPositionSeven},
                 {kPositionTwo,   kPositionFive, kPositionEight},
                 {kPositionThree, kPositionSix,  kPositionNine}};
        vector<vector<int>> diagWinPossibilities
                {{kPositionOne,   kPositionFive, kPositionNine},
                 {kPositionThree, kPositionFive, kPositionSeven}};

        CheckWins(board, rowWinPossibilities);
        CheckWins(board, colWinPossibilities);
        CheckWins(board, diagWinPossibilities);

        if ((OWinCounter > 1)
            || (OWinCounter == 1 && XWinCounter == 1)
            || (OWinCounter == 1 && XCount > OCount)
            || (XWinCounter == 1 && OCount == XCount)) {
            return TicTacToeState::UnreachableState;
        } else if (XWinCounter == 1
                   || (XWinCounter == kTwoDirections && XCount == kMaxXs && OCount == kMaxOs)) {
            return TicTacToeState::Xwins;
        } else if (OWinCounter == 1) {
            return TicTacToeState::Owins;
        }
        return TicTacToeState::NoWinner;

    }

    int CharacterCounter(std::string board, char letter) {
        int characterCount = 0;
        for (std::string::size_type i = 0; i < board.size(); i++) {
            if (board[i] == letter) {
                characterCount++;
            }
        }
        return characterCount;
    }

    void InitializePositionArrays(std::string board) {
        for (std::string::size_type i = 0; i < board.size(); i++) {
            if (board[i] == 'x') {
                XPositions[i] = (i + 1);
                OPositions[i] = 0;
            } else if (board[i] == 'o') {
                OPositions[i] = (i + 1);
                XPositions[i] = 0;
            } else {
                XPositions[i] = 0;
                OPositions[i] = 0;
            }
        }
    }

    int CheckWins(std::string board, std::vector<std::vector<int>> winPossibilities) {
        int XEqualsCounter = 0;
        int OEqualsCounter = 0;

        for (int i = 0; i < winPossibilities.size(); i++) {
            for (int j = 0; j < winPossibilities[i].size(); j++) {
                if (XPositions[winPossibilities[i][j] - 1] == winPossibilities[i][j]) {
                    XEqualsCounter++;
                }
                if (OPositions[winPossibilities[i][j] - 1] == winPossibilities[i][j]) {
                    OEqualsCounter++;
                }
            }
            if (XEqualsCounter == 3) {
                XWinCounter++;
            }
            if (OEqualsCounter == 3) {
                OWinCounter++;
            }
            XEqualsCounter = 0;
            OEqualsCounter = 0;
        }
    }
} // namespace tictactoe
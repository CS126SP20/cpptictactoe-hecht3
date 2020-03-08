// Copyright 2020 Connell Hecht. All rights reserved.

#include <tictactoe/tictactoe.h>

#include <algorithm>

namespace tictactoe {

    using std::string;
    using namespace std;


    /** The size of a tic-tac-toe board. */
    const int kBoardSize = 9;
    /**
     * Used for when X wins in two directions, which is possible in a few
     * scenarios.
     */
    const int kTwoDirections = 2;
    /** The maximum number of each character possible on a board. */
    const int kMaxXs = 5;
    const int kMaxOs = 4;
    /** Used to check if three characters appear in a row on a board. */
    const int kThreeInARow = 3;
    /** The matrix representing the ways for a player to win a row. */
    const vector<vector<int>> kRowWinPossibilities
      {{1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}};
    /** The matrix representing the ways for a player to win a column. */
    const vector<vector<int>> kColWinPossibilities
      {{1, 4, 7},
       {2, 5, 8},
       {3, 6, 9}};
    /** The matrix representing the ways for a player to win a diagonal. */
    const vector<vector<int>> kDiagWinPossibilities
      {{1, 5, 9},
       {3, 5, 7}};

    /** The counters used to keep track of how many wins a player has. */
    int XWinCounter;
    int OWinCounter;

    /**
     * The matrices representing the positions of each character
     * on the board.
     */
    int XPositions[kBoardSize];
    int OPositions[kBoardSize];

    /** Counts the number of characters for each player in the board. */
    int CharacterCounter(std::string board, char letter);

    /**
     * Creates arrays that represent the positions of the players on the
     * board
     */
    void InitializePositionArrays(std::string board);

    /** Checks how many wins each player has on the board */
    void CheckWins(std::vector<std::vector<int>> winPossibilities);


    /**
     * The main driver method for evaluating the given board. Contains all the
     * logic for evaluating the gameState and is in charge of returning
     * the final evaluation.
     *
     * @param boardState the board of the given game.
     * @return the result of the given game which is one of the enums from the
     *         header class
     */
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

      CheckWins(kRowWinPossibilities);
      CheckWins(kColWinPossibilities);
      CheckWins(kDiagWinPossibilities);

      // UnreachableState is checked first because nothing else should be
      // evaluated if an impossible/unfair game was played.
      if ((OWinCounter > 1)
          || (OWinCounter == 1 && XWinCounter == 1)
          || (OWinCounter == 1 && XCount > OCount)
          || (XWinCounter == 1 && OCount == XCount)) {
        return TicTacToeState::UnreachableState;
      } else if (XWinCounter == 1
                 || (XWinCounter == kTwoDirections && XCount == kMaxXs
                     && OCount == kMaxOs)) {
        return TicTacToeState::Xwins;
      } else if (OWinCounter == 1) {
        return TicTacToeState::Owins;
      }
      return TicTacToeState::NoWinner;

    }

    /**
     * A simple function that counts the number of characters in a passed board.
     * The results are checked in the evaluateBoard method to make sure there
     * are not more O's than X's and that there's at most 1 more X than O's.
     *
     * @param board the board of the given game.
     */
    int CharacterCounter(std::string board, char letter) {
      int characterCount = 0;
      for (std::string::size_type i = 0; i < board.size(); i++) {
        if (board[i] == letter) {
          characterCount++;
        }
      }
      return characterCount;
    }

    /**
     * Initializes the arrays of the X and O characters on the board to reflect
     * their positions using an ordinal system. If there is an X in the upper
     * left corner of the board then the X position array will contain a 1 in
     * the first array spot, if there is an O to the right of that X then the
     * O positions array will contain a 2 in the second array spot, etc.
     * Each number placed in the array corresponds to its position in the
     * array itself as well as the actual spot on the board, with the count
     * starting at 1 instead of 0.
     *
     * @param board the board of the given game.
     */
    void InitializePositionArrays(std::string board) {
      for (std::string::size_type i = 0; i < board.size(); i++) {
        if (board[i] == 'x') {
          // 1 is added so that space 1 is 1, space 2 is 2, etc,
          // instead of starting to count spaces at 0.
          // This makes the board and win scenarios a bit easier to think about.
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

    /**
     * Checks for winners given an array containing the possible positions for
     * a win scenario. It checks for equality between the winPossibilities array
     * and the position array for each character. If 3 instances of equality are
     * found in a row, it counts that as a win for the relevant character.
     *
     * @param winPossibilities the array that represents the positions of
     * characters for a player to win.
     */
    void CheckWins(std::vector<std::vector<int>> winPossibilities) {
      int XEqualsCounter = 0;
      int OEqualsCounter = 0;

      for (int i = 0; i < winPossibilities.size(); i++) {
        for (int j = 0; j < winPossibilities[i].size(); j++) {
          // 1 is subtracted from win possibilities because we want the 0 based
          // index to get the element from the positions array.
          if (XPositions[winPossibilities[i][j] - 1] ==
              winPossibilities[i][j]) {
            XEqualsCounter++;
          }
          if (OPositions[winPossibilities[i][j] - 1] ==
              winPossibilities[i][j]) {
            OEqualsCounter++;
          }
        }
        if (XEqualsCounter == kThreeInARow) {
          XWinCounter++;
        }
        if (OEqualsCounter == kThreeInARow) {
          OWinCounter++;
        }
        // The equals counters are reset for each iteration of win possibilities
        // but the win counters are not reset because they are used for
        // evaluation in the evaluation method.
        XEqualsCounter = 0;
        OEqualsCounter = 0;
      }
    }
} // namespace tictactoe
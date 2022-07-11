#include<bits/stdc++.h>

using namespace std;

void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
    bool isValid(vector < vector < char >> & board, int row, int col, char c) {

  for (int i = 0; i < 9; i++) //We loop in the whole board and check valdity
  {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solve(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) //Loop for the whole board
  {
    for (int j = 0; j < board[0].size(); j++)
     {
      if (board[i][j] == '.')
       {
        for (char c = '1'; c <= '9'; c++)//Try every possible number
        
         {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;

            if (solve(board))
              return true;
            else
              board[i][j] = '.';
          }
        }

        return false;
      }
    }
  }
  return true;
}
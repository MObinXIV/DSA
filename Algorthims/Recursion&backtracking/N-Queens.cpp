#include<bits/stdc++.h>

using namespace std;

bool isSafe(int row , int col , vector<string>&board,int n)
{
 int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
}

void Solve(int col , vector<string>&board,vector<vector<string>>&ans,int n )
{
    //Base case for reaching the last nth row
    if(col==n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0  ; row <n ; row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col]='Q';//assign the value for the current cell
            Solve(col+1,board,ans,n);
            //backtrack
            board[row][col]='.';
        }
    }
}

 vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i = 0  ; i<n;i++)
        {
            board[i]=s;//assign all the board with empty or dot val
        }
        Solve(0,board,ans,n);
        return ans; 

    }
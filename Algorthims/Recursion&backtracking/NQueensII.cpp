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


void Solve(int col , vector<string>&board,int n,int &s )

{
    if(col==n)s++;

    for (int row = 0 ; row<n;row++)    
    {
        if( isSafe(row,col,board,n))
        {
            board[row][col]='Q';
            Solve(col+1,board,n,s);
            board[row][col]='.';
        }
    }
  
}

int totalNQueens(int n) {
         vector<string>board(n);
        string s(n,'.');
        for(int i = 0  ; i<n;i++)board[i]=s;
    int sum=0;
         Solve(0,board,n,sum);
    return sum;
    }
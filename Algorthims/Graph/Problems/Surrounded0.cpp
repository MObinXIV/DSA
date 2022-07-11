#include <bits/stdc++.h>

using namespace std;

/*
The idea is we will mark all the boundary guys in grid to be 1's then convert them to O's
Remaining uncell guys will be X's 
*/

void dfs(vector<vector<char>>&arr,int i , int j , int n , int m )
{
    if (i>=0 && i<=n-1 && j>=0 && j<=m-1 && arr[i][j]=='O')
    {
        arr[i][j]='1';
        dfs(arr,i+1,j,n,m);
        dfs(arr,i-1,j,n,m);
        dfs(arr,i,j-1,n,m);
        dfs(arr,i,j+1,n,m);
    }
}

void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        //Mark all boundary cells to 0 
        for (int i =0 ; i<n;i++)
        {
            for (int j = 0 ; j<m ;j++)
            {
                if(i==0 || j==0 || i==n-1||j==m-1)//Check for boundary to go depth on the cell 
                dfs(board,i,j,n,m);
            }
        }
        
        for (int i =0 ; i<n;i++)
        {
            for (int j = 0 ; j<m;j++)
            {
                if(board[i][j]=='1') board[i][j]='O';
                else
                board[i][j]='X';
            }
        }
        
    }
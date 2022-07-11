#include<bits/stdc++.h>

using namespace std;

/*
The idea is that i will only care about the 1's who aren't related to boundaries else I'll set the others to 0 

*/

void dfs (vector<vector<int>>&arr , int i , int j , int n , int m )
{
    if (i>=0 && i<=n-1 && j>=0 && j<=m-1 && arr[i][j]==1)
    {
        arr[i][j]=0;
        dfs(arr,i+1,j,n,m);
        dfs(arr,i-1,j,n,m);
        dfs(arr,i,j-1,n,m);
        dfs(arr,i,j+1,n,m);
    }
}
int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //Mark all boundary cells to 0 
        for (int i =0 ; i<n;i++)
        {
            for (int j = 0 ; j<m ;j++)
            {
                if(i==0 || j==0 || i==n-1||j==m-1)//Check for boundary to go depth on the cell 
                dfs(grid,i,j,n,m);
            }
        }
        int c=0;
        for (int i =0 ; i<n;i++)
        {
            for (int j = 0 ; j<m;j++)
            if(grid[i][j]==1)c++;
        }
        return c;
    }
#include<bits/stdc++.h>

using namespace std;
int  dfs (vector<vector<int>> &matrix,int i,int j,int r,int c)
{
    if(i<0 || i>=r || j<0 || j>=c || matrix[i][j]!=1)return 0;  //Boundary case for matrix or vis case

    matrix[i][j]=2;//Mark as visited 

    return (1+dfs(matrix,i+1,j,r,c)+dfs(matrix,i,j+1,r,c)+dfs(matrix,i-1,j,r,c)+dfs(matrix,i,j-1,r,c));//Add 1 in canse of function T


}
int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result=0;
        for(int i =0 ; i<n;i++)
        {
            for(int j = 0  ; j<m;j++){
            if(grid[i][j]==1) result=max(result,dfs(grid,i,j,n,m));
            }

        }
        return result;
    }

#include<bits/stdc++.h>

using namespace std;
int f(int i , int j,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if(i==0 && j==0) return arr[i][j];
    if (i<0 || j<0) return 1e9;//Maximum as possible
    if(dp[i][j]!=-1) return dp[i][j];
    int up=arr[i][j]+f(i-1,j,arr,dp);
    int left=arr[i][j]+f(i,j-1,arr,dp);
    return dp[i][j]=min(up,left);

}

int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       vector<int>prev(m,0);
        for (int i =0 ;  i < n ; i++)
        {
            vector<int>temp(m,0);
            for (int j =0 ; j < m ; j++)
            {
                if(i==0 && j==0)temp[j]=grid[i][j];
                else
                {
                    int up=1e9,left=1e9;
                    if(i>0) up=grid[i][j]+prev[j];
                    if(j>0) left=grid[i][j]+temp[j-1];
                   temp[j]=min(up,left);
                }
            
            }
            prev=temp;
        }
        return prev[m-1];
        
    }
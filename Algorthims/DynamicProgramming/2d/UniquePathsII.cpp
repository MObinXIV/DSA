#include<bits/stdc++.h>

using namespace std;

int f (int i , int j , vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if ( i<0 || j<0) return 0 ; 

    if(arr[i][j]==1)return 0;

    if(i==0 &&j==0)return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    int up=f(i-1,j,arr,dp);
    int left=f(i,j-1,arr,dp);
    return dp[i][j]=up+left;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       for (int i =0 ; i<n;i++)
       {
           for (int j =0 ; j <  m ; j++)
           {
               if(obstacleGrid[i][j]==1){
            dp[i][j]=0;
           
          }
               else if (i==0 && j==0 ) {dp[i][j]=1;continue;}
               else{
               int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;}

           }
       }
       return dp[n-1][m-1];
    }




    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
        vector<int>prev(m,0);
       for (int i =0 ; i<n;i++)
       {
           vector<int> temp(m,0);
           for (int j =0 ; j <  m ; j++)
           {
               if(obstacleGrid[i][j]==1){
            temp[j]=0;
           
          }
               else if (i==0 && j==0 ) {temp[j]=1;continue;}
               else{
               int up=0;
          int left = 0;
          
          if(i>0) 
            up = prev[j];
          if(j>0)
            left = temp[j-1];
            
          temp[j] = up+left;}

           }
           prev=temp;
       }
       return prev[m-1];
    }
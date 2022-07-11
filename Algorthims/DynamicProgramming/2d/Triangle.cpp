#include<bits/stdc++.h>

using namespace std;
int f(vector<vector<int>>&arr, int i , int j , vector<vector<int>>&dp)
{
    if(i==arr.size()-1) return arr[i][j];
    if(dp[i][j]!=-1) return  dp[i][j];
    int l = arr[i][j]+f(arr,i+1,j,dp);
    int r = arr[i][j]+f(arr,i+1,j+1,dp);
    return dp[i][j]=min(l,r);
}

 int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int> > dp(n,vector<int>(n,-1));
    return f(triangle,0,0,dp);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
       vector<int>prev(n,0);
       vector<int>temp(n,0);
        for (int j = 0 ; j <n ; j++)prev[j]=triangle[n-1][j];
        
        for (int i = n-2;i>=0;i--)
        {
            
            for (int j = i ; j>=0;j--)
            {
                int l = triangle[i][j]+prev[j];
                int r = triangle[i][j]+prev[j+1];
                temp[j]=min(l,r);
            }
            prev=temp;
        }
        return prev[0];
    }
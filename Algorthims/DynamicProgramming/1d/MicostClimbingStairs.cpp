#include<bits/stdc++.h>

using namespace std;
int f( int ind ,vector<int>&arr, vector<int>&dp)
{
    if(ind==0) return arr[ind];
    if(ind == 1) return arr[ind];
    if(dp[ind]!=-1) return dp[ind];
    int l = arr[ind]+f(ind-1,arr,dp);
    int r = arr[ind]+f(ind-2,arr,dp);
    return dp[ind]=min(l,r);
    
}
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(f(n-1,cost,dp),f(n-2,cost,dp));//This is the tricky in problem we sepearte it for 0 and 1 begining 
        
    }

    int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int>dp(n,0);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for (int i =2;i<n;i++)
    {
        int l = cost[i]+dp[i-1];
    int r = cost[i]+dp[i-2];
     dp[i]=min(l,r);
    }
    return min(dp[n-1],dp[n-2]);

        
    }

    
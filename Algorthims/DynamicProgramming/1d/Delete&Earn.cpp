//The main idea in summing all one elemet

#include<bits/stdc++.h>

using namespace std;

int f(int n , vector<int>&arr , vector<int>&dp)
{
      if(n>=arr.size()) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = max(arr[n]+f(n+2,arr,dp),f(n+1,arr,dp));
}
int deleteAndEarn(vector<int>& nums) {
        vector<int>dp(10001,-1);
            vector<int>mp(10001,0);
            //Generate array of element sum & apply the houserobber logic
            for(auto it :nums)mp[it]+=it;
    return f(0,mp,dp);
        
    }
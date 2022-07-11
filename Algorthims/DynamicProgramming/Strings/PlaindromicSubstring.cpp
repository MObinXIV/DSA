#include<bits/stdc++.h>

using namespace std;

bool pls(int l , int r , string &s , vector<vector<int>>&dp)
{
    if(l >= r )return 1 ;
    
    if(dp[l][r]!=-1)return dp[l][r];

    if(s[l]!=s[r])return dp[l][r]= 0;

    return dp[l][r]=pls(l+1,r-1,s,dp);
}
int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int cnt=0;

        for(int i = 0 ; i<n ;i++)
        {
            for(int j  = i;j<n;j++)
            {
                if(pls(i,j,s,dp))cnt++;
            }
        }
        return cnt;
    }
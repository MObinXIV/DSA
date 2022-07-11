#include<bits/stdc++.h>

using namespace std;

int f (int n , int m , string &s , string &t , vector<vector<int>>&dp )
{
    //Base Case we get 0 from the function in case of getting out with neg value
    if(n < 0 || m<0)return 0;


    if(dp[n][m]!=-1)return dp[n][m];

    // Matching case 

    if(s[n]==t[m]) return dp[n][m]= 1+ f(n-1, m-1 , s,t,dp);//We increase the subsequence by one 

    // In case of not matching 
    return dp[n][m]=max(f(n-1,m,s,t,dp),f(n,m-1,s,t,dp));//We try all the possibilities for both and take the maximum one 

}

int lcs (string s , string t )
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
    return f (n-1  ,  m-1 , s , t,dp);
}



//Tabulation 
//The change her it the right shifiting when we copy the base case we right shift the index by 1 
int lcs2 (string s , string t )
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
    for(int i = 0 ; i<=n;i++)
    dp[i][0]=0;
    for(int j = 0 ; j<=m;j++)
    dp[0][j]=0;

    for(int i = 1 ; i<=n;i++)
    {
        for(int j = 1 ; j<=m;j++)
        {
             if(s[i-1]==t[j-1])  dp[n][m]= 1+ dp[i-1][j-1];//We increase the subsequence by one 
             else
    // In case of not matching 
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];

}
//Space Optimized approach
int lcs3 (string s , string t )
{
    int n = s.size();
    int m = t.size();
   vector<int>prev(m+1,0);//We assign our first row with zeros , no need for loop to assign it as no need for assigning of col at all
   vector<int>cur(m+1,0);
    

    for(int i = 1 ; i<=n;i++)
    {
        for(int j = 1 ; j<=m;j++)
        {
             if(s[i-1]==t[j-1]) return cur[j]= 1+ prev[j-1];//We increase the subsequence by one 
             else
    // In case of not matching 
        cur[j]=max(prev[j],cur[j-1]);
        }
        prev=cur;
    }
    return prev[m];

}

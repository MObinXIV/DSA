#include<bits/stdc++.h>

using namespace std;

bool f ( int ind1 , int ind2 ,int ind3 , string s1 ,string s2 , string s3 , vector<vector<int>>&dp )
{
    if(ind1<0 || ind2 <0)return false;
    if(ind3 == 0 && ind1==0 && ind2==0 )return true; 
     if(ind3==s3.size())return false; // handle 1 char case 
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    
   if(s1[ind1]==s3[ind3]) return dp[ind1] [ind2]=f(ind1-1,ind2,ind3-1,s1,s2,s3,dp);
   else if (s2[ind2]==s3[ind3])return dp[ind1] [ind2]=f(ind1,ind2-1,ind3-1,s1,s2,s3,dp);
    return dp[ind1][ind2]=false;
}

bool isInterleave(string s1, string s2, string s3) {
        int i = s1.size(),j= s2.size(),k=s3.size();
        vector<vector<int>>dp(i+1, vector<int>(j+1,-1));
        return f(i, j , k , s1 , s2 , s3 , dp);
        
    }



     bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        
        int m = s1.length();
        int n = s2.length();
        // Base case:: 
        
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true; // both strings are empty
        
        for(int j = 1; j <= n; j++){                           // COnsider the case if s2 is empty, row is static and col is dynamic
            dp[0][j] = (dp[0][j-1] and s2[j-1] == s3[j-1]);
        }
        
        for(int i = 1; i <= m; i++){
            dp[i][0] = (dp[i-1][0] and s1[i-1] == s3[i-1]);   // COnsider the case if s1 is empty, col is static and row is dynamic
        }
        
        //States i and j = 1 to m and n 
        //Recursive condition dp[i][j] = dp[i][j-1] and s2[j-1] == s3[i+j-1] || dp[i-1][j] and s1[i-1] == s3[i+j -1];
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i][j-1] and s2[j-1] == s3[i+j-1] || dp[i-1][j] and s1[i-1] == s3[i+j -1];
            }
        }
        return dp[m][n];
    }
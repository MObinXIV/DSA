#include<bits/stdc++.h>

using namespace std;

// It has to be consecutive 
//By applying the tabulation approach we observe that we increase the  cnt by 1+ the value of it's prev guy 1+ dp[i-1][j-1]in case of matching else keep it 0
int LCS (string s , string t )
{
    int n = s.size();
    int m = t.size();
    vector<int>cur(m+1,0) , prev(m+1,0);
    int ans =0 ; 
    for(int i = 1 ; i<=n ;i++)
    {
        for (int j = 1 ;j<=n;j++ )
        {
            if(s[i-1]==t[j-1])
            {
                cur[j]=1+prev[j-1];
                ans=max(ans,cur[j]);
            }

            else //fill it with 0
            cur [j]=0;
        }
    }
}
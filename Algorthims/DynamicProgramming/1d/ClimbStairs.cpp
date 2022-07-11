#include<bits/stdc++.h>

using namespace std; 
int f(int  ind ,vector<int>&dp)
{
    if(ind == 0 ) return 1;
    if (ind == 1) return 1;
    return dp[ind]=f(ind-1,dp)+f(ind-2,dp);
}
int climbStairs(int n) {
        int prev2=1;
  int prev=1;
  for (int i = 2 ; i <=n ; i++)
  {
      int curi=prev2+prev;
      prev2=prev;
      prev=curi;
  }
    return prev;
    }
int main()

{
//same as fibonacci
}
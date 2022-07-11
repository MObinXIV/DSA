#include <bits/stdc++.h>

using namespace std;

int f(int n, vector<int>& dp){
     if (n == 0 || n == 1){
            return n;
        }
        if(n == 2){
            return 1;
        }
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp)+f(n-3,dp);
}
//space optimize 
 int tribonacci(int n) {
        int a =0,b=1,c=1;
        int res;
        for (int i = 3 ; i<=n;i++)
        {
            res=a+b+c;
            a=b;
            b=c;
            c=res;
        }
        return c;
    }

int main() {
    //Normal tabulation
    int n =25;
  vector<int>dp(n,0);
  dp[0]=0;
  dp[1]=1;
  dp[2]=1;
  for(int i = 3 ; i<=n;i++)
  {
      dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
  }
  cout<<dp[n];
}


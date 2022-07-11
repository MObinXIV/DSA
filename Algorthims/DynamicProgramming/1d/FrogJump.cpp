#include<bits/stdc++.h>

using namespace std;
/*
-- base case reutrn 0 as we not move at all 
-- we move our indexes + the lost energy and take the minmum between all 
dp allow us to choose the best choice for 1 ind 
*/
int f(int ind, vector<int> &arr,vector<int>&dp)
{
    if(ind ==0)return 0;
    if(dp[ind]!=-1) return dp[ind];
    int twoJump=INT_MAX;//we define it as max to keep it big in the restricted case 

    int oneJump=f(ind-1,arr,dp) +abs(arr[ind]-arr[ind-1]);
    if(ind>1) //To avoid -1 case when we at 1 ind we can't go far to 2 jumps
    twoJump=f(ind-2,arr,dp)+abs(arr[ind]-arr[ind-2]);
    return dp[ind]=min(oneJump,twoJump);
}

int main()
{
    vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];

}



#include <bits/stdc++.h>

using namespace std;


int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
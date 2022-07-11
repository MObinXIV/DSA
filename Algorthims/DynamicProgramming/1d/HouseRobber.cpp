#include<bits/stdc++.h>

using namespace std;
int f(int n , vector<int>&nums , vector<int>&dp)
{
    if (n==0) return nums[n];//if we reach our 0 ind we return it 
    if (n<0)return 0;//if we get our of boundary we return 0
    if (dp[n]!= -1 ) return dp[n];

    int pick= nums[n]+f(n-2 , nums , dp);//pick the current element and add it to it's -2 neighbor
    int notPick = 0 + f(n-1 , nums , dp);//don't pick it and go to the next guy
    return dp[n]=max(pick , notPick);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,-1);
    return f ( n-1, nums , dp);
    
        
    }
    int f(int n, vector<int>& arr, vector<int>& dp){
        dp[0]=arr[0];
        for (int i=1;i<=n;i++)
        {
            int pick=arr[i];
            if(i>1)//To handle -1 case
            pick+=dp[i-2];
            
            int nonPick=0+dp[i];
            dp[i]= max(pick , nonPick);
        }
        return dp[n-1];
    }
    int f2(int n, vector<int>& arr){
        int prev1=arr[0];
        int prev2=0;
        for (int i=1;i<=n;i++)
        {
            int pick=arr[i];
            if(i>1)//To handle -1 case
            pick+=prev2;
            
            int nonPick=0+prev1;

            int curi= max(pick , nonPick);
            prev2=prev1;
            prev1=curi;
        }
        return prev1;
    }

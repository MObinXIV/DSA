#include<bits/stdc++.h>

using namespace std;
int maxSubArray(vector<int>& nums) {
        int sum = 0 ; 
        int maxi=INT_MIN;
        for (auto it : nums)
        {
            sum+=it;
            maxi=max(sum,maxi);
            if(sum<0)sum=0;
        }
        return maxi;
    }
   int maxi;
    int f (int ind , vector<int>&nums,vector<int>&dp)
    {
        if(ind==0)return nums[ind];
           if(dp[ind]!=-1)return dp[ind];


        int notTake=nums[ind];

         int take=nums[ind]+f(ind-1,nums,dp);
         maxi=max(maxi,max(notTake,take));
         return dp[ind]=max(take,notTake);
    }
    int maxSubArray(vector<int>& nums) {
        maxi=nums[0];
        int n=nums.size();
        vector<int>dp(n,-1);
         f(n-1,nums,dp);
        return maxi;
    }
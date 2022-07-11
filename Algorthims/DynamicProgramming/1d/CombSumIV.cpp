//https://leetcode.com/problems/combination-sum-iv/
#include<bits/stdc++.h>

using namespace std;
//I generate the combination from 0 -> n for every number of the array 
int f (int tar , vector<int>&arr, vector <int>&dp)
{
    if(tar==0)return 1 ;//If I make the target 0 
     
     if(dp[tar]!=-1)return dp[tar];
     int ans =0;//The backtrack step

     for(int i = 0 ; i<arr.size();i++) // Instead of generating from indx ->n we generate from 0 to ->n for each index 
     {
        if(arr[i]<=tar) ans+=f(tar-arr[i] , arr, dp);//I keep calling the same function for arr[i] till it hits the case of hit the base case 

     }
     return dp[tar]=ans;
}
int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int>dp(n,-1);
        return f(target,nums,dp);
    }
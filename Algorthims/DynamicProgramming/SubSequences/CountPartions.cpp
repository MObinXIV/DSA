#include<bits/stdc++.h>

using namespace std;

int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector
<int>> &dp){

     if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken);
}

bool canPartitionKSubsets(vector<int>& nums, int k) {

    int n = nums.size();
    int totSum=0;
    for(int i =0 ; i<n;i++) totSum+=nums[i];
    if(totSum-k<0) return false;
    if((totSum-k)%2==1) return false;
    int s2 = (totSum-k)/2;

    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    if(countPartitionsUtil(n-1,s2,nums,dp)==0)return false;
    else
    return true;
    }
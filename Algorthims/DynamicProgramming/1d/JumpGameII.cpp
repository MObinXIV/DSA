#include<bits/stdc++.h>
using namespace std;

//We will take the minmum value for every element 

int f ( vector<int>&arr,int ind , int n,vector<int>&dp )
{
    if(ind>=n)return 0;
   if(arr[ind] == 0){
            return INT_MAX;
        }

    if(dp[ind]!=-1)return dp[ind];
    int minVal=INT_MAX;
    for (int i = 1 ; i<=arr[ind];i++)
    minVal=min(minVal,f(arr,ind+i,n,dp));
    return dp[ind]=minVal+1;//1+f

}

 int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || nums[0]==0)return INT_MAX;
        vector<int>dp(n,1e9);
        dp[0]=0;
        // Find the minimum number of jumps to reach arr[i]
        for(int i =1 ; i<n;i++)
        {
            dp[i] = INT_MAX;
            for(int j = 0 ; j<i ; j++)
            {
                if(i<=j+nums[j]&&dp[j]!=INT_MAX)//Valdiate that when we jump our end is position i , we take the min to reach it
                {//برزع اول قيمة صغيرة هتقابلنى 
                    dp[i] = min(dp[i], dp[j] + 1);
                break;
                }
            }

        }
        return dp[n-1];
    }

    


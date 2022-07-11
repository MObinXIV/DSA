#include<bits/stdc++.h>

using namespace std;

int f ( vector<int>&arr,int ind , int target,vector<vector<int>>&dp)
{
    if (ind ==0 )
    {
        if(target%arr[ind]==0)return 1; //We will take the number if it's only divided by our target
        else
        return 1e9;
    }
    if(dp[ind][target]!=-1)return dp[ind][target];

    int notTake= 0 + f(arr,ind-1,target,dp);

    int Take=INT_MAX;

    if(arr[ind]<=target) Take=1+f(arr,ind,target-arr[ind],dp);

    return dp[ind][target]=min(Take,notTake);
}

int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,-1));
    int ans =  f(arr, n-1, T, dp);
    if(ans >= 1e9) return -1;
    return ans;
}

int minimumElements(vector<int>& arr, int T){
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,-1));

    //We will check if tha from 0 to target if target% arr[i] the 0th ind will be 1
    for (int i =0 ; i< T;i++)
    {
        if(i%arr[i]==0) dp[0][i]=i/arr[i];
        else
        dp[0][i]=1e9;
    }
    for (int i = 1 ; i< n ;i++)
    {
        for (int j = 0 ; j<T;j++)
        {
            int notTake= 0 + dp[i-1][j];

    int Take=INT_MAX;

    if(arr[i]<=j) Take=1+dp[i][i-arr[i]];

     dp[i][j]=min(Take,notTake);
        }
    }
}

int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<int> prev(T+1,0), cur(T+1,0);
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];
                
             cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    
    int ans = prev[T];
    if(ans >=1e9) return -1;
    return ans;
}
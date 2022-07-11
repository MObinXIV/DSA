#include<bits/stdc++.h>

using namespace std;
int f (vector<int>&arr,int ind , int target , vector<vector<int>>&dp)
{
    if(ind ==0 )
    {
        return(target%arr[0]==0);//We return 1 in case we have reach 
        
    }
    if (dp[ind][target]!=-1)return dp[ind ][target];
    int notTake=0+f(arr,ind-1,target,dp);
    int  take =0;
    if(arr[ind]<=target)
    take=f(arr,ind,target-arr[ind],dp);
    return dp[ind][target]=take+notTake;
}
int countWaysToMakeChange(vector<int>& arr, int n, int T){
    
    vector<vector<int>> dp(n,vector<int>(T+1,-1));
    return f(arr,n-1, T, dp);
}

long f2(vector<int>& arr, int n, int T){
    
    vector<vector<long>> dp(n,vector<long>(T+1,0));
    
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            dp[0][i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=T;target++){
            long notTaken = dp[ind-1][target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = dp[ind][target-arr[ind]];
                
            dp[ind][target] = notTaken + taken;
        }
    }
    
    return dp[n-1][T];
}

long f3(vector<int>& arr, int n, int T){
    
    vector<long> prev(T+1,0);
    
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            prev[i]=1;
        // Else condition is automatically fulfilled,
        // as prev array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        vector<long> cur(T+1,0);
        for(int target=0;target<=T;target++){
            long notTaken = prev[target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = cur[target-arr[ind]];
                
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    
    return prev[T];
}
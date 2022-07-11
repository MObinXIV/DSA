#include<bits/stdc++.h>

using namespace std;

int f (vector<int>&wt,vector<int>&val , int ind , int w , vector<vector<int>>&dp )

{
    if (ind ==0 )
    {
        // in case the weight can be picked 
        if(wt[0]<=w)return wt[0];

        //else we can't pick it 

        else
        return 0;
    }

    //Not pick case 
    int notPcik=0+f(wt, val , ind-1,w, dp);

    int pick=INT_MIN;

    if(w<=wt[ind])
    pick=val[ind]+f(wt, val , ind-1,w-wt[ind], dp);

    return dp[ind][w]=max(pick,notPcik);

}


int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}




int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<int> prev(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=W; cap>=0; cap--){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
    }
    
    return prev[W];
}
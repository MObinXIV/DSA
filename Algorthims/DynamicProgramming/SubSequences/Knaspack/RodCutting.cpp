#include<bits/stdc++.h>

using namespace std;

int f (vector<int>&price,int ind , int n ,vector<vector<int>>&dp)
{
    if(ind==0)return n*price[0];//We take n of the 0ht index

    if (dp[ind][n]!=-1)return dp[ind][n];

    int notTake=0+f(price,ind-1,n,dp);
    //Take will has it's restructions 
    //I will take only if I'm less than n 
    int take=INT_MIN;

    int rodlength=ind+1;//To see if i'm less than n or not 

    if(rodlength<=n)//I'll pick in this case only 
    take= price[ind]+f(price,ind-1,n-rodlength,dp);
    return dp[ind][n]=max(take,notTake);
}

int cutRod(vector<int>& price,int N) {

    vector<vector<int>> dp(N,vector<int>(N+1,-1));
    return f(price,N-1,N,dp);
}

int cutRod2(vector<int>& price,int N) {

    vector<vector<int>> dp(N,vector<int>(N+1,-1));
    for(int i  = 0 ; i<N ; i++)dp[0][i]=i*price[0];

    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + dp[ind][length-rodLength];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[N-1][N];


}

int cutRod(vector<int>& price,int N) {

    vector<int> cur (N+1,0);
    
    for(int i=0; i<=N; i++){
        cur[i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + cur[length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + cur[length-rodLength];
        
             cur[length] = max(notTaken,taken);   
        }
    }
    
    return cur[N];
}



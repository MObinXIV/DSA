#include<bits/stdc++.h>

using namespace std;

//I'll make a hash set to hash my values till end and the 0 val will not be considered , بتهيش عشان تعد و تنط براحتك 
int f(vector<int>&arr , vector<int>&cost,int ind ,vector<int>&dp )
{
    if(ind>365) return 0;
    //check if the hash is 0 

    if(dp[ind]!=-1)return dp[ind];

    if ( arr[ind]==0)return dp[ind] = f(arr,cost,ind+1,dp); //We don't need to check we move only to next ind

    int a=cost[0]+f(arr,cost,ind+1,dp);
     int b=cost[1]+f(arr,cost,ind+7,dp);
      int c=cost[2]+f(arr,cost,ind+30,dp);

      return dp[ind]=min(min(a,b),c);

}
 int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>arr(366,0);//hash_map
        vector<int>dp(366,-1);
        for(int i =0 ; i<n;i++)
        {
            arr[days[i]]++;
        }
        return f(arr,costs,1,dp);
    }
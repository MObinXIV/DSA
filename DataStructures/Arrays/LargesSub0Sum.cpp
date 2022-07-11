#include<bits/stdc++.h>

using namespace std;

int maxLen(vector<int>&a, int n)
    {   
        int maxi=0;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i =0; i< n ; i++)
        {
            sum+=a[i];
            if(sum==0)maxi=i+1;
            else
            {
                if(mp.find(sum)!=mp.end())//I check if I found the current sum or Not 
                maxi=max(maxi, i- mp[sum]);// This means from The last appearing prefix sum to my current 
                else 
                mp[sum] = i;//Assign the prefix 
            }
        }
        return maxi ;
    }
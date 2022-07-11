//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
#include<bits/stdc++.h>

using namespace std;

int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
        sort(dep,dep+n);
        int i = 0 , j =1;
        int res =1 , plat=1;
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j])//We can't replace a train in the same platform in this case 
            {
                plat++;
                i++;
            }
            else if(arr[i]>dep[i])//here we can place so decrease the platforms by 1 and move from departed
            {
                plat--;
                j++;
            }
            res=max(res,plat);
        }
        return res;
    }
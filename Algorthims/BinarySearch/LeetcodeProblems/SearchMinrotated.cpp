#include<bits/stdc++.h>
using namespace std;
int f(vector<int>&arr)
{
    int low=0, hi=arr.size()-1;
    while(low<=hi)
    {
        int mid=(low+hi)>>1;
       
        if(arr[hi]<arr[mid])
        {
            hi=mid;//You are not sure if it's our answer or not
        }
        else
        low=mid+1;
    }
    //always end at low ==high
    return arr[low];
}
int main()
{
    vector<int>nums = {4,5,6,7,0,1,2};
    cout<<f(nums);
    }
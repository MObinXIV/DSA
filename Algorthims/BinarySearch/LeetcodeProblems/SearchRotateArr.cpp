#include<bits/stdc++.h>

using namespace std;
//Any place we stand in is usually have the right half or the left half sorted 
int BinarySearch(vector<int>&arr,  int x)
{
    int low=0,high=arr.size()-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;//equavilant to /2;
        if(arr[mid]==x)return mid;
        if(arr[low]<=arr[mid])//check if the left half is sorted
        {
            if(arr[low]<=x && arr[mid]>=x)//we search in the left side if this is true
            high=mid-1;//elemenate the right half 
            else
            low=mid+1;//elemenate the left half 

        }
        else
        {
            if(arr[high]>=x && arr[mid]<=x)//check for right half valdity
            low=mid+1;
            else
            high=mid-1;
        }
    }
    return -1;
}


int search(vector<int>& nums, int target) {
        return BinarySearch(nums,target);
    }
int main()
{
    vector<int>nums = {4,5,6,7,0,1,2};
    int target = 3;
    cout<<search(nums,target);
    }
#include<bits/stdc++.h>

using namespace std;
int findPeakElement(vector<int>& nums) {
        int low =0,high=nums.size()-1;
        while (low<high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid+1])high=mid;//here I'm assure the peak is in the left portion
            else low =mid+1;
        }
        return nums[low];
    }
    int search(vector<int>&nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
     int findPeakElement(vector<int>&nums) {
        return search(nums, 0, nums.size() - 1);
    }
    

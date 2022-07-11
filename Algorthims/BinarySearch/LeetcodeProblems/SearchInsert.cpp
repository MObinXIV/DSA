#include<bits/stdc++.h>

using namespace std;
//by observation we return l if we not find our target
 int searchInsert(vector<int>& nums, int target) {
        int n =nums.size();
        int h=n-1, l =0;
        while(l<=h)
        {
            int mid=(h+l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) l=mid+1;
            else
            h=mid-1;
        }
        return l;
    }

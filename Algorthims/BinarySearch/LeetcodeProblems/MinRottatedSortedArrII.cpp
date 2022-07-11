#include<bits/stdc++.h>
//The only difference between it and one the equlity case 
int findMin(vector<int>& nums) {
         int low=0, hi=nums.size()-1;
    while(low<hi)
    {
        int mid=(low+hi)>>1;
        
        if(nums[hi]>nums[mid]) // for this reason I'm sure that my right is absoultelry bigger than me 
        {
            hi=mid;//low still as we saw as it might be my answer
        }
        else if (nums[mid]>nums[hi])
        low=mid+1;//You are not sure if it's our answer or not 
        else
        hi--; //handle duplucate case 
    }
    //always end at low ==high
    return nums[low];
    }
//https://leetcode.com/problems/maximum-product-of-three-numbers/
#include<bits/stdc++.h>

using namespace std;
//In general we can obtain the largest 3 values by get the max between the product of last 2 or the product of last 1 with minmum 2 
int maximumProduct(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());

        int maxPro=nums[0]*nums[1]*nums[n-1];//Critical case to take last one which biggest with the smallest 2 gives us the biggest one as we can have 2 neg at first giv positive bigger one 
        int minPro= nums[n-1]*nums[n-2]*nums[n-3];// The last 3 is biggest
        return max(maxPro,minPro);
    }

    //We can obtain the 5 values through loop with no sort to get complexity O(n)instead of O(nlogn)
int maximumProduct(vector<int>& nums) {
    int min1=INT_MAX , min2=INT_MAX;
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
    for (int it : nums)
    {
        if(it <=min1)//Update the 2 minvals
        {
            min2=min1;
            min1=it;
        }
        else if(it<min2)min2=it;
        if(it>=max1)
        {
            max3=max2;
            max2=max1;
            max1=it;
        }
        else if(it>= max2)
        {
            max3=max2;
            max2=it;
        }
        else if(it>max3)max3=it;

    }
    int res=max(max1*max2*max3 , max1*min1*min2);
    return res;
    }
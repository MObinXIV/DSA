#include<bits/stdc++.h>

using namespace std;
 void nextPermutation(vector<int>& nums) {
     int n = nums.size(), k ,l;

     for (k = n-2;k>=0;k--)//we iterate from the back to find our first index 
     {
         if(nums[k]<nums[k+1]) break;
     }
     if(k<0)//This means we have the largest lexographicall order so we reverse it 
     reverse(nums.begin(),nums.end());
     else
     {
         for (l=n-1;l>k;l--)
         {
             if(nums[l]>nums[k]) break;
         }
         swap(nums[l],nums[k]);
        
     }

        
    }
 
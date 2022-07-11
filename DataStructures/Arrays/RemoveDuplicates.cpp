#include<bits/stdc++.h>

using namespace std;
/*
The brute force approach is very easy we push them in set and then empty it 
*/

//2 pointers approach
/*
We use a pointer i  which we move it forward only in case of any changing happened in the nums array when j moves forward 
*/
int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0 ;
        int i =0 ; 
        for(int j = 0 ; j<n ;j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
        
        }
        return i+1;
    }
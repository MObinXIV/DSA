#include<bits/stdc++.h>

using namespace std;
//Kadane's Algorithm
int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        int maxi=0;
        for(int it : nums)
        {
            if(it==1)
            {
                cnt++;
                maxi=max(maxi,cnt);
            }
            else
            cnt=0;
        }
        return maxi;
    }
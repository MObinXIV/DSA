#include<bits/stdc++.h>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n = nums.size();
        for (int i =0 ; i<n;i++)
        {
            if(mp.find(target-mp[i])!=mp.end())//If we find the other guy in map
            {
                ans.push_back(mp[target-nums[i]]);//we push the other guy 
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;//we assign the current guy to our map
        }
        return ans;
    }
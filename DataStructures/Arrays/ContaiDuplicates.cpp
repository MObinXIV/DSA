#include<bits/stdc++.h>

using namespace std;
 bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (auto it :nums)
        {
            mp[it]++;
            if(mp[it]>=2) return true;
        }
        return false;
    }
    //sorting solution hahah
    

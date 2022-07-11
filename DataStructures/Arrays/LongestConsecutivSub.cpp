#include<bits/stdc++.h>

using namespace std;

 int longestConsecutive(vector<int>& nums) {
        set<int>hash_set;
        for(int num : nums)hash_set.insert(num);
        int long_streak=0;
        for(int num : nums)
        {
            if (!hash_set.count(num-1))//Here I check if this num is the first of my sequence else I'll not take it 
            {
                int cur_num=num;
                int streak=1;
                while (hash_set.count(cur_num+1))
                {
                    cur_num+1;
                    streak+1;
                }
                long_streak=max(long_streak,streak);
            }
        }
        return long_streak;
    }
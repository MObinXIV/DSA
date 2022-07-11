//https://leetcode.com/problems/insert-interval/
#include<bits/stdc++.h>

using namespace std;
//Another variation of merge intervals algorithm
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        
       vector<vector<int>>complete_interval;
       vector<int> tempInterval=intervals[0];
        for(auto it : intervals)
        {
            if(it[0]<=tempInterval[1])
            tempInterval[1]=max(tempInterval[1],it[1]);
           else 
           {
            complete_interval.push_back(tempInterval);
            tempInterval=it;
           } 
        }
        complete_interval.push_back(tempInterval);
        return complete_interval;

    }

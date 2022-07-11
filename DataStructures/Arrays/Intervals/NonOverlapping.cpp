//https://leetcode.com/problems/non-overlapping-intervals/
#include<bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
     sort (intervals.begin(),intervals.end());
        int n = intervals.size();
       
        int cnt =0 ; 
        int l = 0 ;
        int r =1 ;
        while(r<n)
        {
            if(intervals[l][1]<=intervals[r][0])//Non overlapping case 
            {
                l=r;
                r++;
            }
            else if(intervals[l][1]<=intervals[r][1])//الاولى بتتقاطع مع التانية فى حتة ساعتها همسح التانية  
            {
                cnt++;
                r++;

            }
            else if(intervals[l][1]>intervals[r][1])// الاولى بتحتوى التانية ساعتها همسح الاولى 
            {
                cnt++;
                l=r;
                r++;
            }
        }
        return cnt;
    }

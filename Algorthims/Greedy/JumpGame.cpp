#include<bits/stdc++.h>

using namespace std;
//If at any moment I reach on 0 this mean I can't reach to end 
//We indicate this with the comparison between our maximum reach with our current index when we cross with index this mean we can't 
//move beyond zero 
bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable =0; // A variable which we will update with our maximum reach 
        for(int i =0 ; i<n ; i++)
        {
            if(i>reachable) return false;//if any moment we can't go beyond I this means we can't cross 0
            reachable=max(reachable,nums[i]+i);//we update with the maximum distance we can reach
        }
        return true;
    }
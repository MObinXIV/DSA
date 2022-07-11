//https://leetcode.com/problems/intersection-of-two-arrays/
#include<bits/stdc++.h>

using namespace std;
 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>hash_set1,hash_set2;
        for(auto it : nums1)hash_set1.emplace(it);
        for(auto it : nums2)hash_set2.emplace(it);
        vector<int>ans;
        for(auto it: hash_set2)
        {
            if(hash_set1.count(it))ans.push_back(it);
        }
        return ans;

    }

    //binary Search approach 
    /*
    هنعمل باينرى سيرش للعنصر بتاع واحد فى السيت التانية و لو لقيناه بنضيه للهاش
    */
   bool SearchTarget(vector<int>& nums, int target) {
        int n =nums.size();
        int h=n-1, l =0;
        while(l<=h)
        {
            int mid=(h+l)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]<target) l=mid+1;
            else
            h=mid-1;
        }
        return false;
    }

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash_set;
        sort(nums2.begin(),nums2.end());
        for(auto it : nums1)
        {
            if(SearchTarget(nums2,it))
            hash_set.emplace(it);
        }
        vector<int>ans;
        for(auto it : hash_set)
        {
            ans.push_back(it);
        }
        return ans;

    }
#include<bits/stdc++.h>

using namespace std;
//hashMap approach
int majorityElement(vector<int>& nums) {
       unordered_map<int,int>mp;
       int n = nums.size()/2;int res;
       for (int i =0 ; i<nums.size();i++)
       {
           mp[nums[i]]++;
           if(mp[nums[i]]>n)
           {
                res = nums[i];
               break;
           }
       }
       return res;
    }
    //sotring Approach
    int majorityElement(vector<int>nums) {
        sort(nums.begin(),nums.end());
        //Always be true according to the fact the element will be repeated more than n/2
        return nums[nums.size()/2];
    }
    //Moore voting (cancling in fact more than [n/2])
    int majorityElement(vector<int>nums)
    {
        int count=0;
        int candidate =0 ; 
        for (int num : nums)
        {
            if (count==0) candidate=num;
            if(num==candidate)count+=1;
            else
            count-=1;
        }
        return  candidate;
    }

#include<bits/stdc++.h>

using namespace std;
//Sliding window technique (Naive)
vector<vector<int>> threeSum(vector<int>& nums) {
        
vector < vector < int >> ans;
  vector < int > temp;
  int i, j, k;
  for (i = 0; i < nums.size() - 2; i++) {
    for (j = i + 1; j < nums.size() - 1; j++) {
      for (k = j + 1; k < nums.size(); k++) {
        temp.clear();
        if (nums[i] + nums[j] + nums[k] == 0) {
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
        }
        if (temp.size() != 0)
          ans.push_back(temp);
      }
    }
  }

  return ans;

    }

    //2nd approach is using hashing to reduce complexity
vector<vector<int>> threeSum(vector<int>& nums) 
{
    unordered_map<int,int>mp;
    for(int it : nums)
    mp[it]++;
    vector<vector<int>>ans;
    int n  =  nums.size();
    for(int i = 0 ; i<n ; i++)
    {
        mp[nums[i]]--;//To consider not take it again 
        for(int  j = i+1;j<n;j++)
        {
            mp[nums[j]]--;
            if(mp.find(-1*(nums[i]+nums[j]))!= mp.end())
            {
                vector<int>lol;
                lol[0]=nums[i];
                lol[1]=nums[j];
                lol[2]=-1*(nums[i]+nums[j]);
                ans.push_back(lol);
            }
        }
    }
//There's a step which we use hash_set and .....
    return ans;
}

//Using 2 pointer technique
/*
I get the first element as constant then , I keep trying to find a sum of 2 = -a 
I skip the duplicates 
*/
vector<vector<int>> threeSum(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>>res;
    for(int i = 0 ; i<n-2;i++)
    {
        if(i==0 || (i>0 && nums[i]!=nums[i-1]))//Here I do skip duplicates and take care of 0 case 
        {
            int lo = i+1 , hi=n-1;
            int target=0-nums[i];//our corresponding target guy
            while(lo<hi)
            {
                if(nums[lo]+nums[hi]==target)
                {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    res.push_back(temp);
                    //I move low & high that all duplicates get ignored 
                    while(lo<hi && nums[lo]==nums[lo+1])lo++;
                    while(lo<hi&&nums[hi]==nums[hi-1])hi--;
                    lo++;
                    hi--;
                }
                else if(nums[lo]+nums[hi]<target) lo ++;
                else hi--;
            }
        }
    }
    return res;
}
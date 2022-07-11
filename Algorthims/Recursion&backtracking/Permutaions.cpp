#include<bits/stdc++.h>

using namespace std;

//BackTracking approach
void Permutations ( int ind , vector<int>&nums, vector<vector<int>>&ans )
{
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = ind ; i <nums.size();i++)
    {
        swap(nums[i],nums[ind]);

        //Call recursion function 
        Permutations(ind+1,nums,ans);

        swap(nums[i],nums[ind]);//Backtracking step
    }
}

//Hashing approach
void permute(vector<int>&ds,vector<int>&arr,vector<vector<int>>&ans,int freq[])
{
    if(ds.size()==arr.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0 ; i <arr.size();i++)
    {
        if(!freq[i])
        {
            ds.push_back(arr[i]);
            freq[i]=1;
            permute(ds,arr,ans,freq);
            freq[i]=0;
            ds.pop_back();

        }
    }
}
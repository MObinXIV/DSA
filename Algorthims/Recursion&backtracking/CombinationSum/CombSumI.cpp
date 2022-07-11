//https://leetcode.com/problems/combination-sum/

#include<bits/stdc++.h>

using namespace std;

void findComb(int ind , int tar,vector<int>&arr, vector<int>&ds,vector<vector<int>>&ans)
{
    //base case 
    if(ind==arr.size())
    {
        if(tar==0) ans.push_back(ds);
        return;
    }

    //Pick Same index call 
    if(arr[ind]<=tar)
    {
        //we call the function with same index
        ds.push_back(arr[ind]); //pick this element
        findComb(ind , tar-arr[ind],arr,ds,ans);
        //pop it when you come back 

        ds.pop_back();

    }

    //Backtracking call (not Pick )
    findComb(ind+1 , tar, arr,ds, ans);
}

vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findComb(0, target, candidates, ds, ans);
      return ans;
    }
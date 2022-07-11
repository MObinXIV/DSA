//https://leetcode.com/problems/combination-sum-iii/submissions/
//Another variation of CombinationSumI -> I treat the numbers from 1 -> 9 as array with unique numbers 
#include<bits/stdc++.h>

using namespace std;
 void f(int ind, int  k , int n , vector<int>&ds , vector<vector<int>>&ans)
{
    if(n== 0 && ds.size()==k)
    {
        ans.push_back(ds);
        return;
    }
    for(int i = ind ; i<=9 ; i++)
    {
        ds.push_back(i);
        f(i+1,k,n-i,ds,ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        f(1,k,n,ds,ans);
        return ans;
    }
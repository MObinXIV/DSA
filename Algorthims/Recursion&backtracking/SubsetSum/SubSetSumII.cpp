#include<bits/stdc++.h>

using namespace std;
void f(int ind , vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans)
{
    ans.push_back(ds);
    for(int i = ind ; i < arr.size() ; i++)

    {
        if(arr[i]==arr[i-1] && i!=ind) continue;
        ds.push_back(arr[i]);
        f(ind+1,arr,ds,ans);
        ds.pop_back();//empty data structure when we back 
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector < vector < int >> ans;
         vector < int > ds;
         sort(nums.begin(), nums.end());
         f(0, nums, ds, ans);
         return ans; 
    }
int main()
{

}
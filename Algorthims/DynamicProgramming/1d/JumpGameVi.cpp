#include<bits/stdc++.h>
using namespace std;
int f(int ind , int k , vector<int>&arr, vector<int>&dp)
{
    if(ind==0)return arr[ind];
    if(dp[ind]!=-1)return dp[ind];
    int ans=-1e9;
    for(int i = 1 ; i<=k;i++)
    {
        if(ind-i>=0)
        {
            int score= f(ind -i, k , arr, dp) +arr[ind];
            ans=max(ans, score);
        }

    }
    return dp[ind]=ans;
}
int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
        vector<int>dp(n,-1);
        return f(n-1,k,nums,dp);
    }

    int maxResult(vector<int>& nums, int k) {
	vector<int> dp(sizeof(nums), INT_MIN);
    multiset<int> s ({ dp[0] = nums[0] });         // set dp[0] = nums[0] and insert it into set
	for(int i = 1; i < size(nums); i++) {
        if(i > k) s.erase(s.find(dp[i - k - 1]));  // erase elements from which we cant jump to current index
        s.insert(dp[i] = *rbegin(s) + nums[i]);    // choose element with max score and jump from that to the current index
    }
	return dp.back();
}
int maxResult(vector<int>& nums, int k) {
	vector<int> dp(sizeof(nums));
	dp[0] = nums[0];
	deque<int> q{ 0 };
	for(int i = 1; i < nums.size(); i++) {
		if(q.front() < i - k) q.pop_front();         // can't reach current index from index stored in q     
		dp[i] = nums[i] + dp[q.front()];             // update max score for current index
		while(!q.empty() && dp[q.back()] <= dp[i])   // pop indices which won't be ever chosen in the future
		    q.pop_back();
		q.push_back(i);                              // insert current index
	}
	return dp.back();
}
//https://leetcode.com/problems/paint-house-iii/submissions/
#include<bits/stdc++.h>

using namespace std;
/*3d Dp problem The problem states that we want to color the houses which not colored with minimum color cost & in the end receive the neighborhoods equal to target
*/
int dp[101][21][101] = {};//Set dp of max nums with zero
    int MAX = 1e9;//Assign the value with int max 
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
            int ans = solve(houses, cost, m, n, target, 0, 0);
            return ans < MAX ? ans : -1;
    }
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i, int p){
        if(i == m || target < 0)//Normal base case 
        {
            if(target == 0)
                return 0;
            
            return MAX;
        }
         if(dp[i][p][target] != 0)
             return dp[i][p][target];
        
        int ans = MAX;
        if(houses[i] == 0){
            for(int k=1; k<=n; k++){ //k->new color
                ans = std::min(ans, solve(houses, cost, m, n, target - (k != p) , i+1, k) + cost[i][k-1]); //keep get the minimum  update it , also subtract target-1 in case of different neighborhood else it subtracted from 0 
            }
        }else{
            ans = solve(houses, cost, m, n, target - (houses[i] != p), i+1, houses[i]);
        }
        return dp[i][p][target] = ans;
    }
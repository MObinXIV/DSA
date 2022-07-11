//https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include<bits/stdc++.h>
using namespace std;

void f(int ind , vector<int>&arr,int n ,  vector<int>&ans,int sum)
{
    if(ind ==n)
    {
        ans.push_back(sum);
        return;
    }
    f(ind+1 , arr, n , ans, sum+arr[ind]);//pick the current element to my sum 

    f(ind+1 , arr, n , ans, sum);//don't pick it to my sum 
    
}

 vector<int> subsetSums(vector<int> arr, int N)
    {
       vector < int > ans;
    f(0, arr, N, ans, 0);
    return ans;
    }

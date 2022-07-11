#include<bits/stdc++.h>

using namespace std;
//We choose The largest permutation after B swaps,So we choose the largest number to replace first always
vector<int> solve(vector<int> &arr, int B) {
    int n = arr.size();
    vector<int>mp(n);
    for (int i = 0; i < n; ++i)
        mp[arr[i]] = i;

    for(int i = 0 ;  i<n &&B;i++)
    {
        // If element is already i'th largest,
        // then no need to swap
        if (arr[i] == n - i)
            continue;
            int temp= mp[n-i];//Get the position
            mp[arr[i]] = mp[n - i];//swap positions in map
        mp[n - i] = i;
        swap(arr[i] , arr[temp]);
        B--;
    }
    return arr;
} 
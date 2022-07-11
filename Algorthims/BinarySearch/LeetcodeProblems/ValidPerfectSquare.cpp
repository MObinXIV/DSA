#include<bits/stdc++.h>

using namespace std;
//regular binary search 
bool isPerfectSquare(int num) {
        int low=1, high=num;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mid*mid==num)return true;
            if(mid*mid<num)low=mid+1;
            else
            high=mid-1;
        }
        return false;

    }

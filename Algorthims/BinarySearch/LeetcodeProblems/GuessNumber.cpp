#include<bits/stdc++.h>

using namespace std;

//Normal binary search with change of the naming by using API
int guessNumber(int n) {
        long low=1,high = n;
    while(low<=high)
    {
        long mid= (high+low)/2;
        int res=guess(mid);
        if(res==0)return mid;
        else if(res<0)
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    return -1;
    }

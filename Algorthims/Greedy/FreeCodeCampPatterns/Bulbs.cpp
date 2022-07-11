//https://www.interviewbit.com/problems/interview-questions/
#include<bits/stdc++.h>

using namespace std;

/*
The idea -> if we have switch with even times we have no need to change the current state of the bulb 
*/
int bulbs(vector<int> &arr) {
    int cnt = 0 ; 
    for (int it : arr)
    {
        if (cnt%2==0)it=it; // I'm not change the current state of the bulb  
        else it=!it;
        // if the current state of the bulb is 1  
        if(it%2==1)continue;
        else // if not i increase the swithces as I'm now 0 
        cnt++;

    }
    return cnt;
}
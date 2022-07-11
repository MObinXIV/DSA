//https://leetcode.com/problems/interval-list-intersections/
#include<bits/stdc++.h>

using namespace std;

 vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    vector<vector<int>>res;
    int n = firstList.size(),m=secondList.size();
    int a =0 , b =0 ;//pointers for the 1st & 2nd list 
    vector<int>temp(2);
    while(a<n && b < m)
    {
        // in case of intersection 
        if(firstList[a][0]<=secondList[b][1]&& firstList[a][1]>=secondList[b][0])//In case of intersection 
        {
            temp[0]=max(firstList[a][0],secondList[b][0]);
            temp[1]=min(firstList[a][1],secondList[b][1]);
            res.push_back(temp);
        }

        //move the pointer to it's next positon according to the smallest guy
        if(firstList[a][1]<secondList[b][1])
        a++;
        else 
        b++;
    }
    return res; 
    }
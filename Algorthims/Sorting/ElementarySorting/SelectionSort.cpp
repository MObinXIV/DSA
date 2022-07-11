#include<bits/stdc++.h>

using namespace std;

void selectioSort(vector<int>&arr,int n )
{
    int minIndex;
    for (int i =  0 ; i<n ; i++)
    {
        minIndex=i;
        for (int j = i+1 ; j<n-1 ; j++)
        {
            if(arr[i]<arr[minIndex])
            minIndex=j;
            swap(arr[minIndex],arr[i]);
        }
    }
}
/*
We always try to sort the item in his place using this algorithm 
*/
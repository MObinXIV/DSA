//Pick not pick technique
#include<bits/stdc++.h>

using namespace std;
int  SubSeq(int ind , vector<int>&ds,int s , int sum , int arr[],int n)
{
    if(ind==n)
    {
        if(s==sum) return 1;
        else return 0;
       
    }
    //pick
    ds.push_back(arr[ind]);
    s+=arr[ind];
    int l=SubSeq(ind+1,ds,s,sum,arr,n) ;
    ds.pop_back();
    //Not Pick
    int r=SubSeq(ind+1,ds,s,sum,arr,n) ;
    return (l+r);
}

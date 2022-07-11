//Pick not pick technique
//Get the 1st subSequence equal to the target sum 
#include<bits/stdc++.h>

using namespace std;
bool  SubSeq(int ind , vector<int>&ds,int s , int sum , int arr[],int n)
{
    if(ind==n)
    {
        if(s==sum){
        for (auto it :ds )
        cout<<it<<" ";
        cout<<endl;
        return true;}
        else // Condition not satisfied
        return false;
    }
    //pick
    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(SubSeq(ind+1,ds,s,sum,arr,n) ==true)return true;
    ds.pop_back();
    //Not Pick
    if(SubSeq(ind+1,ds,s,sum,arr,n) ==true)return true;
    return false;
}

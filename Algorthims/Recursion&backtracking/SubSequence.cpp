//Pick not pick technique
#include<bits/stdc++.h>

using namespace std;
void SubSeq(int ind , vector<int>&ds, int arr[],int n)
{
    if(ind==n)
    {
        for (auto it :ds )
        cout<<it<<" ";
        cout<<endl;
        return ;
    }
    //pick
    ds.push_back(arr[ind]);
    SubSeq(ind+1,ds,arr,n);
    ds.pop_back();
    //Not Pick
    SubSeq(ind+1,ds,arr,n);

}

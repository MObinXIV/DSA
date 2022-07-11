#include<bits/stdc++.h>

using namespace std;
bool BinarySearch(vector<int>&arr, int n , int x)
{
    int low=0,high = n-1;
    while(low<=high)
    {
        int mid= (high+low)/2;
        if(arr[mid]==x)return true;
        if(arr[mid]<x)
        {
            low=mid+1;
        }
        else
        high=mid-1;
    }
    return false;
}
void fast() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}
int main()

{
    fast();
    int n  , k ;
    cin>>n>>k;
    vector<int>arr(n);
    for (int i =0 ; i<n;i++)cin>>arr[i];

    for(int i = 0 ; i<k;i++)
    {
        int x;
        cin>>x;
        if(BinarySearch(arr,n,x))cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}
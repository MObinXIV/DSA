#include<bits/stdc++.h>

using namespace std;
int BinarySearch(vector<int>&arr, int n , int x)
{
    int low=0,high = n;
    int mid;
    while(low<high)
    {
        int mid= (high+low)/2;
        //if(arr[mid]==x) return mid;
         if(arr[mid]<x) low=mid+1;
        else
        high=mid;
        
    }
    return low+1;
}
void fast() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}
int main()
{
    fast();
    int n , k;
    cin>>n>>k;
    vector<int>arr(n);
    for (int i = 0; i<n;i++)cin>>arr[i];
    for(int i=0;i<k;i++)
    {
        int x ;
        cin>>x;
        //if (x < *min_element(arr.begin(),arr.end())) cout<<0<<endl;
        //else
        cout<<BinarySearch(arr,n,x)<<endl;
    }

}
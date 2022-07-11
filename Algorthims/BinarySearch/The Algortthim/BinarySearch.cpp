#include<bits/stdc++.h>

using namespace std;
//Iterative 

int BinarySearch(vector<int>&arr, int n , int x)
{
    int low=0,high = n-1;
    while(low<=high)
    {
        int mid= (high+low)/2;
        if(arr[mid]==x)return mid;
        if(arr[mid]<x)
        {
            low=mid+1;
        }
        else
        high=mid-1;
    }
    return -1;
}
//recursive method
int BinarySearch2(vector<int>&arr,int low,int high ,int x  )
{
    if(high>=low){
    int mid=low+(low+high)/2;
    if(arr[mid]==x)return mid;
    if(arr[mid]>x) return BinarySearch2(arr,low,mid-1,x);
    
    return BinarySearch2(arr,low+1, high,x);}
    return -1;
}
//On array hahaha
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
int main()
{
vector<int> arr = { 2, 3, 4, 10, 40 };
    int x = 10;
   
    int result = BinarySearch(arr, arr.size()-1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
}
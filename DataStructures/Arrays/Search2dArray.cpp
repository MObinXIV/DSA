#include<bits/stdc++.h>

using namespace std;
//1st approach 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int  n = matrix.size();
    int  m = matrix[0].size();
    int j = m-1;
    int i = 0;
    while(i<n && j>=0)
    {
        if (matrix[i][j]==target) return true;
        else if (matrix [i][j] >target) j--;
        else
        i++;
    }
        
    }
//Binary Search approach 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi=(n*m)-1;
        while(lo<=hi)
        {
            int mid=(lo + (hi-lo)/2);
            if(matrix[mid/m][mid%m]==target)return true;
            if(matrix[mid/m][mid%m]>target) hi=mid-1;
            else
            lo= mid+1;
        }
        return false ;
    }

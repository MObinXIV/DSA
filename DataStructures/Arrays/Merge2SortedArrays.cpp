#include<bits/stdc++.h>

using namespace std;

//naive-> sort in 3rd array then swap 
void merge(int arr1[], int arr2[], int n, int m) {
    int arr3[n+m];
    int k = 0;
    for (int i = 0; i < n; i++) {
      arr3[k++] = arr1[i];
    }
    for (int i = 0; i < m; i++) {
      arr3[k++] = arr2[i];
    }
    sort(arr3,arr3+m+n);
    k = 0;
    for (int i = 0; i < n; i++) {
      arr1[i] = arr3[k++];
    }
    for (int i = 0; i < m; i++) {
      arr2[i] = arr3[k++];
    }

  }

  //second approach swap then sort 2nd
  void merge(int arr1[], int arr2[], int n, int m) {
  // code here
  int i, k;
  for (i = 0; i < n; i++) {
    // take first element from arr1 
    // compare it with first element of second array
    // if condition match, then swap
    if (arr1[i] > arr2[0]) {
      int temp = arr1[i];
      arr1[i] = arr2[0];
      arr2[0] = temp;
    }

    // then sort the second array
    // put the element in its correct position
    // so that next cycle can swap elements correctly
    int first = arr2[0];
    // insertion sort is used here
    for (k = 1; k < m && arr2[k] < first; k++) {
      arr2[k - 1] = arr2[k];
    }
    arr2[k - 1] = first;
  }
}

//Gap method

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap= (m+n+1)/2;
        int i = 0 ; 
        while(gap>0)
        {
            int i = 0;
            int j = gap;
            while(j<(m+n))
            {
                if(j<n && nums1[i]>nums1[j])
                swap (nums1[i],nums1[j]);

                else if (j>=n && i<n && nums1[i] > nums2[j]) swap(nums1[i],nums2[j]);
                else if (j>=n && i>n && nums2[i] > nums2[j])swap(nums2[i],nums2[j]);
                 i++;
            j++;
            }
            //if we reach 1 we done 
            if (gap == 1) {
            gap = 0;
    } else { //recalculate 
      gap = ceil((float) gap / 2);
    }
           
        }
    }

     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int j=0;
	 for (int i=m;i<nums1.size();i++)
	 {
		 nums1[i]=nums2[j];
		 j++;
	 }
	 sort(nums1.begin(),nums1.end());
    }

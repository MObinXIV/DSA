#include<bits/stdc++.h>

using namespace std;
//max area of cake
/*
الفكرة انى بجيب اكبر جزأ من الكيكة ممكن يبقى اللى فوق او اللى تحت او حد من النص و بستف عليه بقى تقسيماتى
و بالنسبة لك عشان بتشوفها بالطول بس ابقى اقلب الكيكة ههههه

*/
int getMaxDiff(int m , vector<int>&arr)
{
    int n = arr.size();
    sort(arr.begin(),arr.end());
    //Get the max between الجزأ الاخير و الجزأ الاول اللى هما مش معانا جوا اللوب 
    int maxi=max(m-arr[n-1],arr[0]);
    for(int i =1 ; i<n;i++)
    maxi=max(maxi,arr[i]-arr[i-1]);
    return maxi;
}
 int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
         return (int)((long)getMaxDiff(h, horizontalCuts)*getMaxDiff(w, verticalCuts)%1000000007);
    }
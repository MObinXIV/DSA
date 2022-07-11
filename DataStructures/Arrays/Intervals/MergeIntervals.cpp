//https://leetcode.com/problems/merge-intervals/
#include<bits/stdc++.h>

using namespace std;
//1st approach 
vector < pair < int, int >> merge(vector < pair < int, int >> & arr) {

  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector < pair < int, int >> ans;

  for (int i = 0; i < n; i++) {
    int start = arr[i].first, end = arr[i].second;

    //since the intervals already lies 
    //in the data structure present we continue
    if (!ans.empty()) {
      if (start <= ans.back().second) {
        continue;
      }
    }

    for (int j = i + 1; j < n; j++) {
      if (arr[j].first <= end) {
        end = arr[j].second;
      }
    }

    ans.push_back({
      start,
      end
    });
  }

  return ans;
}

//Optimal one
/*
برتب المجموعات فى الاراى 
باخد اول اراى و اسيفه
بلف على عناصر الماتريكس فيكتور فيكتور و بقارن اذا كان العنصر الاصغر اقل من عنصر الفيكتور اللى معيا بمرج بالكبير فى الاند و كدا كدا انا معيا الاصغر دايمًا بما انى بادئ
باول عنصر فى حالة خلاص بطلت ميرج بقوم عامل بوش ف الريسلت و ابدايت الاراى بتاعى 
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedIntervals;
        if (intervals.size()==0)
        return mergedIntervals;
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval=intervals[0];//this how we take 1st interval of size 2 
        for (auto it : intervals)

        {
            //The overlapping case 
            if(it[0]<=tempInterval[1])//we compare our 1st array item with the second item of our interval 
            tempInterval[1]=max(tempInterval[1],it[1]);//take the max between it end and interval end 

            //Not case 

            else 
            {
                mergedIntervals.push_back(tempInterval);//we Push the interval after the overlapping finished
                tempInterval=it;//assign our interval to new value 
            }
        }
        mergedIntervals.push_back(tempInterval);//we push the last remaining interval after the loop end
        return mergedIntervals;

    }
/*
Initially take the gap as (m+n)/2;
Take as a pointer1 = 0 and pointer2 = gap.
Run a oop from pointer1 &  pointer2 to  m+n and whenever arr[pointer2]<arr[pointer1], just swap those.
After completion of the loop reduce the gap as gap=gap/2.
Repeat the process until gap>0.
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int j=0;
	 for (int i=m;i<nums1.size();i++)
	 {
		 nums1[i]=nums2[j];
		 j++;
	 }
	 sort(nums1.begin(),nums1.end());
    }
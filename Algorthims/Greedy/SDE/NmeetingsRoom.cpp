#include<bits/stdc++.h>

using namespace std;

//We will sort according to finishing times & maintain the order in order to indexes in case of equality

struct meeting 
{
    int start;
    int end ; 
    int idx;
};
bool comp( meeting m1, meeting m2)
{
    return m1.end<m2.end && m1.idx<m2.idx;
}
void maxMeetings(int start[], int end[], int n)
    {
        //Create an array of meeting type ,
        meeting meet[n];
        for(int i = 0 ; i<n ; i++)
        meet[i].start=start[i],meet[i].end=end[i],meet[i].idx=i;//I push all the the meeting with there indexes in my map
        sort(meet,meet+n,comp);
        vector < int > answer;

      int limit = meet[0].end;
      answer.push_back(meet[0].idx);

      for (int i = 1; i < n; i++) {
         if (meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].idx);
         }
      }
      cout<<"The order in which the meetings will be performed is "<<endl;
      for (int i = 0; i < answer.size(); i++) {
         cout << answer[i] << " ";
      }
    }

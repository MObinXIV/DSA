#include<bits/stdc++.h>
using namespace std;
//Sort by back/first , then apply greedy
bool Wsort(vector<int>&v1, vector<int>&v2)
{
    return v1[1]>v2[1];
}
 int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),Wsort);
        int n = boxTypes.size();
        int lol=0;
        int i = 0;
       while(i<n && truckSize>0)
        {
            if(truckSize>=boxTypes[i][0]){
            lol += boxTypes[i][0]*boxTypes[i][1];  
                truckSize-=boxTypes[i][0]; }
                else // I'll Take my remaining size from the current boxes
                {
                    lol+=truckSize *boxTypes[i][1];
                    truckSize-=boxTypes[i][0];
                }
            
            i++;
        }
        return lol;
    }
#include<bits/stdc++.h>

using namespace std;

int f ( int day , int last ,vector<vector<int>>&points,vector<vector<int>>&dp)
{
    if(dp[day][last]!=-1) return dp[day][last];

    if(day==0)
    {
        int maxi=0;
        for (int task = 0 ; task <3;task++)
        {
            if(task!=last)
            maxi=max(maxi,points[0][task]);
        }
       return dp[day][last] = maxi;

    }
    
    int maxi=0;
    for (int task=0 ; task<3;task++)
    {
        if(task!=last){
        int point=points[day][task]+f(day-1,task , points,dp);//we take the task of the prev day and the max of our function
        maxi=max(maxi,point);}
    }
    return dp[day][last]= maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
	    return f(n-1,3,points,dp);

}

//Tabulation form
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,0));
	dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
  for (int day = 1 ; day<n;day++)
  {
      for (int last=0;last<4;last++)
      {
          dp[day][last] = 0;
    for (int task=0 ; task<3;task++)
    {
        if(task!=last){
        int point=points[day][task]+dp[day-1][task];//we take the task of the prev day and the max of our function
        dp[day][last]=max(dp[day][last],point);
    } 
      }
  }

}
return dp[n-1][3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>prev(4,0);
	prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
  for (int day = 1 ; day<n;day++)
  {
      vector<int>temp(4,0);
      for (int last=0;last<4;last++)
      {
         
    for (int task=0 ; task<3;task++)
    {
        if(task!=last){
        int point=points[day][task]+prev[task];//we take the task of the prev day and the max of our function
        temp[last]=max(temp[last],point);
    } 
      }
  }
  prev=temp;
}
return prev[3];
}
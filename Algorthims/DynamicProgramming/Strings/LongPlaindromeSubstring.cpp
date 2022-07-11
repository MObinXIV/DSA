#include<bits/stdc++.h>

using namespace std;
//Firstly -> fuck this problem
// We set the diagonals to true base case 
//then we set the 2's if one is true 
// the start with the 3's check if the left guy+1 and right guy-1 is set or not if we set else we not 
string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp,0,sizeof dp);
        int st = 0 , end=1;
        // put all the diagonals with 1 as 1 char always plaindrome 
        for(int i = 0 ; i< n ; i++)dp[i][i]=1;
        //check for 2's

        for(int i = 0 ; i<n ; i++)
        {
            if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;//Set the value wit true 
            st = i;//Get the start value with the new i
            end = 2;//The end 
        }
        }
       for(int j=2;j<n;j++)
    {
        for(int i=0;i< n-j;i++)
        {  
            int left=i; //start point
            int right = i+j;  //ending point
            
            if(dp[left+1][right-1]==1 && s[left]==s[right]) 
            {
                dp[left][right]=1; st=i; 
                end=j+1; 
            }        
        }
    }
   return s.substr(st, end);
    }


    //Expanding Center 

     
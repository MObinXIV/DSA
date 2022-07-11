//https://leetcode.com/problems/longest-palindrome/
#include<bits/stdc++.h>

using namespace std;
//The intuition is very simple, we only count the number of odds and subtract it from size 
 int longestPalindrome(string s) {
       int odd=0;
       for(char c = 'A';c<='z';c++)
       odd+=count(s.begin(),s.end(),c)&1;//count the occurrences of c in string 

       return s.size()-odd+(odd > 0);//(odd > 0) it will add 1 in case we have odds to the result to return it max
        
    }
int longestPalindrome(string s) {
        int count [128];
        for (char c: s)
            count[c]++;

        int ans = 0;
        for (int v: count) {
            ans += v / 2 * 2;
            if (ans % 2 == 0 && v % 2 == 1)
                ans++;
        }
        return ans;
    }
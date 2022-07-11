#include<bits/stdc++.h>

using namespace std;
/*
We take the same code from the problem lcs and we get the strings by 
the matching from the tabulation table 
I take the element in case of matching 
In case of not I move to my previous element in row or colmun 
*/
void lcs(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

  int len = dp[n][m];//The length of string is the value of the lcs 
  int i = n;
  int j = m;

  int index = len - 1;
  string str = "";
  for (int k = 1; k <= len; k++) {
    str += "$"; // dummy string
  }

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) //In matching case 
    {
      str[index] = s1[i - 1];
      index--;
      i--;
      j--;
    } 
    else if (s1[i - 1] > s2[j - 1]) //not matching but the the max is in row val 
    {
      i--;
    } 
    else j--;//opposite 
  }
  cout << str;
}
int lcs(string &s1, string &s2){
    
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                ans = max(ans,val);
            }
            else
                dp[i][j] = 0;
        }
    }
    
    return ans;
    
}
#include<bits/stdc++.h>

using namespace std;

int f (int i , int j1 , int j2,int r,int c  , vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
{
    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
    return -1e9;
    if(i== r-1)
    {
        if (j1==j2)return grid[i][j1];
        else
        return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int maxi =INT_MIN;
    //The row only increase by so we take care of the col only and we genereate the loop instead of typing 9 functions 
    for (int dj1=-1;dj1<=+1;dj1++)
    {
        for (int dj2=-1; dj2<=+1;dj2++)
        {
            int ans;
            if (j1 == j2)
        ans = grid[i][j1] + f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
      else
        ans = grid[i][j1] + grid[i][j2] + f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
       
            maxi=max(maxi,ans);
        }
    }
    return dp[i][j1][j2]= maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
    int r = grid.size();
    int c =grid[0].size();
   vector < vector < vector < int >>> dp(r, vector < vector < int >> (c, vector < int> (c, -1)));
        return f(0,0,c-1,r,c,grid,dp);
    }


    #include<bits/stdc++.h>

using namespace std;

int maxChocoUtil(int i, int j1, int j2, int n, int m, vector < vector < int >> 
& grid, vector < vector < vector < int >>> & dp) {
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e9;

  if (i == n - 1) {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = INT_MIN;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      int ans;
      if (j1 == j2)
        ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
      else
        ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n,
        m, grid, dp);
      maxi = max(maxi, ans);
    }
  }
  return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector < vector < int >> & grid) {

  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int
  > (m, -1)));

  return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}

int main() {

   vector<vector<int> > matrix{
      {2,3,1,2},
      {3,4,2,2},
      {5,6,3,5},
  };

  int n = matrix.size();
  int m = matrix[0].size();

  cout << maximumChocolates(n, m, matrix);
}


#include<bits/stdc++.h>

using namespace std;

int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  // Write your code here.
  vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);

          }
        }
        cur[j1][j2] = maxi;
      }
    }
    front = cur;
  }

  return front[0][m - 1];

}

int main() {

  vector<vector<int> > matrix{
      {2,3,1,2},
      {3,4,2,2},
      {5,6,3,5},
  };

  int n = matrix.size();
  int m = matrix[0].size();

  cout << maximumChocolates(n, m, matrix);
}
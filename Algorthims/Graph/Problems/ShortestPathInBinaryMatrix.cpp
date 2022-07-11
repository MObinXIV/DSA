#include<bits/stdc++.h>
int arri[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
int arrj[8] = {0, +1, 1, 1, 0, -1, -1, -1};
using namespace std;
//I'll Try all possible ways and the first way reaches to my
int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,-1));
    dist[0][0]=0;
    
    queue<pair<int, int>> q;
        q.push({0,0});  
          
    while(!q.empty())
    {
        auto lol=q.front();
        int x =q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0 ; i<8  ; i++)
        {
            int a= x+arri[i];
            int b =y+arrj[i];
            if(a>=0 && a<n && b <n && b>0&&dist[a][b]==-1&& grid[a][b]==0)//As the unweighted there no need to compare
            {
                dist[a][b]=1+dist[x][y];
                q.push({a,b});
            }
            
        }
    }
    return dist[n-1][m-1];

}
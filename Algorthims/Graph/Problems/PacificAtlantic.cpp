//traverse 2 queues and take the common visited between them (1 for pacific and other for atlentic)
#include<bits/stdc++.h>

using namespace std;
int x[5] = { 0, 0, -1, 1 };
int y[5] = { 1, -1, 0, 0 };
bool safe(int i, int j, int N, int M)
{
    if (i < 0 || j < 0 || i >= N || j >= M)
        return false;
    return true;
}
//Bfs traversal we do the traversal in the constrain to the common case which that our guy is bigger than the traversed

void Bfs(vector<vector<int>>matrix,int n , int m , queue<pair<int,int>>q,vector<vector<bool>>&vis)
{
    while(!q.empty())
    {
        pair<int,int>node=q.front();
        q.pop();
        vis[node.first][node.second]=true;//Mark our nodes in visited 
        for (int i = 0 ; i <4;i++)
        {
            int nx=node.first+x[i];
            int ny=node.second+y[i];
            //check the valdity case 
            if(safe(nx, ny, n, m)&&matrix[nx][ny]>=matrix[node.first][node.second]&&!vis[nx][ny])
            {
                q.push({nx,ny});//push it in our queue
                vis[nx][ny]=true;//visited one 
            }
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //Create 2 visited arrays for the 2 queues 
        queue<pair<int, int> > q1, q2;
        int n = heights.size(),m=heights[0].size();
        vector<vector<bool>>vis1(n , vector<bool>(m,0)),vis2(n , vector<bool>(m,0));

        //Fill the queues , q will be pacific and the other will be atlantic 
        ///We traverse every col in the row to end 
        for(int i = 0 ; i<m;i++)
        {
            q1.push({0,i});//push the upper bound part to the qeueue 
            q2.push({n-1,i});//push the down boud part 
        }
        //We have no need to go the the last row guy as it filled already
        for(int j =0;j<n-1;j++)
        {
            q1.push({j+1,0});
            q2.push({ j, m - 1 });
        }
        //Call the bfs for for the 2 queues seperately 
        Bfs(heights,n,m,q1,vis1);
         Bfs(heights,n,m,q2,vis2);
         vector<vector<int>>res;
         for(int i =0; i<n ;i++)
         {
            for (int j=0 ; j <m ;j++)
            {
                if(vis1[i][j]&& vis2[i][j])res.push_back({i,j});
            }
         }
         return res;
    }
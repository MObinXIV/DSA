#include<bits/stdc++.h>
using namespace std;
  
//Shortes path algorithm for each one in the matrix 
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
          int n = mat.size();
        int m = mat[0].size();
        if(n==0)return mat;
        //Define the dist array
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        //We will push 0 as if the 1st index has the 1 value we are not allowed to assign dist 0 to it(The tip in the algorithm)
        for(int i =0 ; i <n ; i++)
        {
            for (int j =0 ; j<m;j++)
            {
                if(mat[i][j]==0)
                {q.push({i,j});dist[i][j]=0;}
            }
        }
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while(!q.empty())
        {
            pair<int, int> node =q.front();
            q.pop();
           
            for(int i = 0 ; i <4 ; i++)
            {
                int cur_x=node.first + dir[i][0],
                 cur_y=node.second + dir[i][1];
                if(cur_x>=0 && cur_x<n && cur_y>=0 && cur_y<m)//validation Step
                {
                    if(dist[cur_x][cur_y]>1+dist[node.first][node.second])
                    {
                        dist[cur_x][cur_y]=1+dist[node.first][node.second];
                        q.push({cur_x,cur_y});
                    }
                }
            }
        }
        return dist;
        
    }
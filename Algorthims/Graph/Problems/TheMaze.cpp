//Check If we can reach to  our target or not through maze 
#include<bits/stdc++.h>

using namespace std;

bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});

        int vis [n ][m];
        for(int i=0 ; i<n ;i++)
        {
            for(int j =0 ; j<m;j++)vis[i][j]=0;
        }
        vis[start[0]] [start[1]]=true;
        while(!q.empty())
        {
            int x = q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==destination[0]&& y==destination[1])return true;
            int dx[]={-1,0,1,0};
            int dy[]={0,+1,0,-1};
            for(int i = 0 ; i<4 ; i++)//Traverse for all 4 directions 
            {
                int newX=x;
                int newY=y;
                while(newX>=0 && newX<n && newY >=0 && newY <m && maze[x][y]==0)//Traverse with  my directions till I hit 1 our getout

                {
                    newX+=dx[i]; 
                    newY+=dy[i];
                }
                newX-=dx[i];//-- step after get out 
                newY-=dy[i];
                if(vis[newX][newY]==0)
                {
                    vis[newX][newY]==1;
                    q.push({newX,newY});
                }
            }


        }
        return false;
    }
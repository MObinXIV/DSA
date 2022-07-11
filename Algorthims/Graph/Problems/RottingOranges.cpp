
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int x , y , time;
    node(int _x, int _y , int _time)
    {
        x=_x;
        y=_y;
        time=_time;
    }
};
 int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        queue<node>q;
        int cntO=0;//to count the number of empty cells for the purpose of posibillty 
        for (int  i = 0 ; i <n  ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                //push all the rotten guys in the queue
                if(grid[i][j]==2) q.push(node(i,j,0));//push indeces and make the time 0
                if(grid[i][j]!=0) cntO++;//count the number of possible rotten ones 
            }
        }
        int ans=0;
        int cnt=0;
        while(!q.empty())
        {
            int x= q.front().x;
            int y = q.front().y;
            int time=q.front().time;
            q.pop();
            cnt++;
            ans = max(ans , time);


            int dx[]={-1 ,0 ,+1,0};//X coordinates
            int dy[]={0,1,0,-1};//Y coordinates 
            //here we make a loop to travers our possible neighbor whome we can rotten 
            for (int i = 0 ; i<4;i++)
            {
                int newX=x+dx[i];//our current pos + possible attack
                int newY=y+dy[i];//our current pos + possible attack
                if(newX>=0  && newX < n &&newY>=0  && newY < m &&grid[newX][newY]==1 )//check for rotten valdity 
                {
                    grid[newX][newY]=2;//Rotten it 
                    q.push(node(newX,newY,time+1));
                }
            }
        }
        if (cnt==cntO) return ans;//This mean I fill all the emptu cells 
        return -1;
    }
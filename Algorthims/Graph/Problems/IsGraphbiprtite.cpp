#include<bits/stdc++.h>

using namespace std;

 #include <bits/stdc++.h>

using namespace std;

bool bipartiteBfs(int src ,vector<vector<int>>& adj,int color[])
{
    queue<int>q;
    color[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int node =q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                q.push(it);
            }
            else if(color[it]==color[node])return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        memset(color,-1,sizeof color);
        for (int i = 0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartiteBfs(i,graph,color))return false;
            }
        }
        return true;
    }
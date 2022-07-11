#include <bits/stdc++.h>

using namespace std;

bool bipartiteBfs(int src , vector<int>adj[],int color[])
{
    queue <int>q;
    q.push(src);
    color[src]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        //I check for all the adj of the current node 
        for (auto it : adj [node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];//Give it a different color from the parent node
                q.push(it);
            }
            // If the current node has the same parent color 
            else if (color[it]==color[node]) return false;
        }
       
    }
     return true ;
}

bool checkbipartite(vector<int>adj[],int n)
{
    int color [n];
    memset(color,-1,sizeof color);
    for(int i = 0 ; i<n ;i++)
    {
        if(color[i]==-1)
        if(!bipartiteBfs(i,adj,color)) return false;
    }
    return true;
}
#include<bits/stdc++.h>

using namespace std;

void Bfs (vector<int>adj[],int n , int src)
{
    int dist[n];
    memset(dist,INT_MAX,sizeof(dist));
    queue<int>q;
    dist[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it : adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it]=dist[node]+1;//Update our current distance with new one 
                q.push(it);
            }
        }
    }

}
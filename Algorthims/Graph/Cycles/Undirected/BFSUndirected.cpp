#include<bits/stdc++.h>
using namespace std;
/*
The idea is that if we have a visted node and it's not equal to  parent there's a cycle 

*/
bool checkCyclic(int s , vector<int>adj[],vector<int>vis)
{
    queue<pair<int,int>>q; // queue to push the current node and parent
    q.push({s,-1});
    while(!q.empty())
    {
        //take our current node and parent 
        int node =q.front().first;
        int parent=q.front().second;
        for (auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;//make it visited
                q.push({it,node});//push it and node to make it the current parent
            }
            else if (parent != it) return true;
        }
    }
    return false;
}
bool isCycle (int n , vector<int>adj[])
{
    vector<int>vis(n+1,0);
    for(int i = 0 ; i<n;i++)
    if(checkCyclic(i,adj,vis)) return true;
    return false;
}
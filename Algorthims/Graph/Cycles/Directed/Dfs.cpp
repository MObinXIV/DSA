/*
* We make 2 vis arrays one for visted and another for dfs visted 
*we use the second to detect a cycle by backtracking when we back from the call & vis still same 
* cycle detected when we find the node visted in the two arrays in the same call
*/
#include<bits/stdc++.h>

using namespace std;
bool checKCycle(int node , vector<int>adj[], vector<int>&vis ,vector<int>dfsVis)
{
    vis[node]=1;
    dfsVis[node]=1;
    for (auto it :adj[node])
    {
        if(!vis[it])
        {
            if(checKCycle(it, adj,vis,dfsVis)) return true;//if i find my node neighbor is in both visited and un we return cycle
        }
        else if (dfsVis[it]) return true;
    }
    dfsVis[node]=0;//Backtrack step
}
bool isCyclic (int n , vector<int>adj[])
{
    vector<int>vis(n,0);
    vector<int>dfsVis(n,0);
    for (int i = 0  ; i<n ; i++)
    {
        if(!vis[i])
        {
            if(checKCycle(i,adj,vis,dfsVis))return true;
         }
    }
    return false;
}

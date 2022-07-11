#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n , m ; 
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];//declare an adj list of size nodes
    for (int i = 0 ; i< m ;i++)
    {
        int u , v,wt;
        cin>>u>>v>>wt;//take the nodes between the edges  and the weight 
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});//we ignore it in case of directed graph
    }
}
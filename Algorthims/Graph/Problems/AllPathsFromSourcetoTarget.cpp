#include<bits/stdc++.h>

using namespace std;
//we only traverse for all the adjacency nodes for the source s
void dfs ( vector<vector<int>>&adj,vector<vector<int>>&res,vector<int>&path,int src)
{
    path.push_back(src);
    if(src==adj.size()-1)res.push_back(path);
    for(auto it :adj[src]) dfs(adj,res,path,src);
    path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(graph, result, path, 0);
        return result;
    }
#include<bits/stdc++.h>

using namespace std;

bool checkCycle (int node , int parent , vector<int>&vis,vector<int>adj[])
{
    vis[node]=1;//Mark node as visited 
    for (auto it : adj[node])//Traverse for adj of node 
    {
        if(!vis[it])//if neighbor is not visited 
        {
            
            if(checkCycle(it, node , vis,adj))return true;//recurse and chceck for true case 
        }
        else if ( it !=parent) return true;//cycle case 
    }
    return false ;//If I got out this when I return No cycle
}
bool isCycle(int n , vector<int>adj[] )
{
    vector<int>vis(n+1,0);
    for (int i =0 ; i<=n;i++)
    {
        if(!vis[i])
        {
            if(checkCycle(i,-1,vis,adj)) return true;
        }
    }
    return false;

}
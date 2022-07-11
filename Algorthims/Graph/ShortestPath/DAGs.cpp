#include<bits/stdc++.h>

using namespace std;

void findTopo(int node , vector<int>&vis,stack<int>&st, vector<pair<int,int>>adj[])
{
    vis[node]=1;
    for (auto it:adj[node])
    {
        if(!vis[it.first])
        {
            findTopo(it.first,vis,st,adj);
        }
    }
    //when we over and return , we push the values we get in the stack
    //It's a last in last out which reverse the process of returning so when
    // I become to my base function I get it first & then my neighbors will after me
    st.push(node);
}
void shortestPath(int src , int n , vector<pair<int,int>>adj[])
{
    vector<int>vis(n,0);
    stack<int>st;
    for(int i =0 ; i<n ;i++)
    if(!vis[i])findTopo(i,vis,st,adj);
    int dist[n];
    memset(dist,INT_MAX,sizeof dist);
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dist[node]!=INT_MAX)//Has a distance before it
        {
            for (auto it : adj[node])
            {
                if (dist[node]+it.second<dist[it.first])
                dist[it.first]=dist[node]+it.second;
            }
        }
    }
}
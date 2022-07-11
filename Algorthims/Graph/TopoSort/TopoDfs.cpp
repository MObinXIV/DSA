#include<bits/stdc++.h>

using namespace std;
void findTopo(int node , vector<int>&vis,stack<int>&st,vector<int>adj[])
{
    vis[node]=1;
    for (auto it:adj[node])
    {
        if(!vis[it])
        {
            findTopo(it,vis,st,adj);
        }
    }
    //when we over and return , we push the values we get in the stack
    //It's a last in last out which reverse the process of returning so when
    // I become to my base function I get it first & then my neighbors will after me
    st.push(node);
}
vector<int>TopoSort(int n , vector<int>adj[])
{
    stack<int>st;
    vector<int>vis(n,0);
    for(int  i = 0 ; i<n;i++)
    {
        findTopo(i,vis,st,adj);
    }

    vector<int>Topo;
    while(!st.empty())
    {
        Topo.push_back(st.top());
        st.pop();
    }
    return Topo;
}
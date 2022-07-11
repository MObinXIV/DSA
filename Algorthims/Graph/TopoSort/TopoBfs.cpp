#include<bits/stdc++.h>

using namespace std;

vector<int>TopoSort(int n , vector<int>adj[])
{
    queue<int>q;
    vector<int>INdegree(n,0);//We take the indgree of each node
    for(int i  = 0 ; i< n ; i++)
    {
        // بزود درجة كل العناصر اللى انا بدخلهم بواحد عملية عكسية ف نفسها يعنى 
        for (auto it:adj[i])
        {
            INdegree[it]++;
        }
    }
    for (int i = 0 ; i<n ; i++)
    if(INdegree[i]==0)q.push(i);//This means it outs only so I keep it first
    vector<int>Topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        Topo.push_back(node);//push my node to the sort
        for (auto it : adj[node])
        {
            INdegree[it]--;//decrease the indgree of the neighbor of my node by 1 
            if(INdegree[it]==0)q.push(it);
        }
       
    return Topo;
}
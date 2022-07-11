/*
Normal Dijkstra we built adj list then apply dijkstra 
at the end we see if there still INTMax value these means we don't have min from source to distenation
*/

#include<bits/stdc++.h>

using namespace std;
const int lol=101;
vector<pair<int, int>> adj[lol];
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //built the adjecncy list 
    for (auto v : times)
    {
        int source = v[0];
        int dest=v[1];
        int time  = v[2];
        adj[source].push_back({dest,time});
    }
     vector<int> signalReceivedAt(n + 1, INT_MAX);
        dijkstra(signalReceivedAt, k, n);
        //Now we will find the maximum value received from source to distenation if there still INTmax we return -1 
        int res=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            res=max(res,signalReceivedAt[i]);

        }

        return res == INT_MAX ? -1 : res;
    }
    
void dijkstra(vector<int>&dist , int source , int n )
{
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//Min heap
    
     
     pq.push({0,source});
     dist[source]=0;
     while(!pq.empty())
     {
        int dis=pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for(auto it : adj [prev])
        {
            int nextNode=it.first;
            int nextDist=it.second;
            if(dist[nextNode]>dis+nextDist)
            {
                dist[nextNode]=dist[prev]+nextDist;
                pq.push({dist[nextNode],nextNode});
            }
            
        }

     }
}

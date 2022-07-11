/*
Normal Dijekstra problem we reserve the path with nodes not weights in reversed order and in case we can't reach the last node we return -1 
*/

/*#include<bits/stdc++.h>

using namespace std;
const int MAX_N = 1e5 + 5;
int main()
{
    int n , m ;
    cin>>n>>m;
    vector<pair<int,int>>g[n+1];
    int a , b , w ;
    for(int i = 0 ; i<m ; i++)
    {
        cin>>a>>b>>w;
         g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    int lol[n+1];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//Min heap
    long long distTo[MAX_N];
    
    distTo[1]=0;
    for(int i = 2; i <= n; i++) {
        distTo[i] = INT_MAX;
    }
    //distTo[source]=1;
    pq.push({0,1});
    while(!pq.empty())
    {
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        for(auto it : g[prev])
        {
            int next=it.first;
            int nextDist=it.second;
            if(distTo[next]>dist+nextDist)//if the distance to the current node is bigger than the distance between it and our prev node the node in Pq we update it 

            {
                lol[next]=prev;
                distTo[next]=distTo[prev]+nextDist;//update the distance 
                pq.push({distTo[next],next});//Push to Pq for the reasons of update 
            }
        }
    }
    if(distTo[n]==INT_MAX)
    {
        cout<<"-1";
        return 0;
    }
    // هفضى الاراى و اعكسه
    vector<int> path;
    int current = n;
    while(current != 1) {
        path.push_back(current);
        current = lol[current];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for(auto it: path)cout<<it<<" ";
    
}*/


#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5; // 100,005
const long long INF = 1e18L + 5; // 10^18
vector<pair<int,int>> edges[MAX_N];
long long dist[MAX_N]; // distance from vertex 1
int parent[MAX_N];
bool visited[MAX_N];
int main() {
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin>>a>>b>>w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    dist[1] = 0;
    for(int i = 2; i <= n; i++) {
        dist[i] = INF;
    }
    // we could also use set to avoid memory limit exceed
    set<pair<long long, int>> s; // pairs (distance, index)
    s.insert({dist[1], 1});
    while(!s.empty()) {
        pair<long long, int> best = *s.begin();
        s.erase(s.begin());
        int a = best.second;
        /*if(visited[a]) {
            continue;
        }
        visited[a] = true;*/
        for(pair<int,int> edge : edges[a]) {
            int b = edge.first;
            int len = edge.second;
            if(dist[a] + len < dist[b]) {
                parent[b] = a;
                dist[b] = dist[a] + len;
                s.insert({dist[b], b});
            }
        }
    }
    if(dist[n]==INF) { 
       cout<<"-1";
        return 0;
    }
    
    vector<int> path;
    int current = n;
    while(current != 1) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for(int x : path) {
        cout<<x<<" ";
    }
    
}



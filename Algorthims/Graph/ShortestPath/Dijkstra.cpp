#include<bits/stdc++.h>

using namespace std;
void dijkestra(int source ,vector<pair<int,int>>g[],int n )
{
    
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//Min heap
    vector<int>distTo(n+1,INT_MAX);
    distTo[source]=0;
    pq.push({0,source});
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
                distTo[next]=distTo[prev]+nextDist;//update the distance 
                pq.push({distTo[next],next});//Push to Pq for the reasons of update 
            }
        }
    }
    cout << "The distances from source " << source << " are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
}
int main()
{
    int n , m , source ;
    cin>>n>>m;
    vector<pair<int,int>>g[n+1];//Graph with number of nodes 
    int a , b ,wt;
    for(int i = 0 ; i<m ;i++)//loop on every node in the edges 
    {
        cin>>a>>b>>wt;
        g[a].push_back({b,wt});
        g[b].push_back({a,wt});
    }
    cin>>source;
    //source=1;
    //dijkestra(source,g,n);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//Min heap
    vector<int>distTo(n+1,INT_MAX);
    distTo[source]=0;
    //distTo[source]=1;
    pq.push({0,source});
    //pq.push({1,source});
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
                distTo[next]=distTo[prev]+nextDist;//update the distance 
                pq.push({distTo[next],next});//Push to Pq for the reasons of update 
            }
        }
    }
    //cout << "The distances from source " << source << " are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	

}
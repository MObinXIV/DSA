#include<bits/stdc++.h>

using namespace std;

vector<int> bfs(int v , vector<int > adj[])
{
    vector<int>vis(v+1,0);//visited array 
    vector<int>bfs;//the resulte bfs traversal array
    for (int i = 1; i <= v; i ++)
    {
        if(!vis[i])
        {
            //we use queue as it's first in first out data structre it will keep the level order as we want it 
            queue<int>q;//queue to store the current node 
            q.push(i);//push the curent node 
            vis[i]=1;//mark the current node as visted 
            while(!q.empty())//while the queue not empty we traverse 
            {
                int node=q.front();//get the the front node of the queue 
                q.pop();//pop the current node from our queue
                bfs.push_back(node);//push the node to bfs traversal 
                for (auto it : adj[i])//get our node's adj vertices 
                {
                    if(!vis[it]){
                      vis[it]=1; //mark the node as visted 
                    q.push(it);//push it to our queue 
                    }
                   
                }
                
            }
        }
    }
    return bfs;
}
void addEdge(vector <int>adj[],int u , int v )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void display(vector < int > & ans) {
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
int main()
{
vector < int > adj[5];

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 4);

  
  vector < int > ans = bfs(5, adj);
  display(ans);
  cout << endl;
}
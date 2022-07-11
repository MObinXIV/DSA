# Graph

    Bfs & Dfs:
    we use both commenly to traverse garph and all the next alogirthms of graph is based on them.
                                                '

## Cylcle detection

- Undirected Graph

>we traverse the graph with normal dfs and for cycle detection , we carry a value parent which is the previous node we visited as long as our neighbor is unvisted or it's visited but it's our parent , we are good otherwise we have a cycle (Note that here we use one visited array and node use a pathVis)

-Dfs->we recures to find an visited unparent node

-Bfs->By using Queue we push every node and do our basic checks

- Directed Graph

-DFS-> We  keep 2 arrays on for visited node and one path visitng , we keep the first as it's and don't change the first one but we change the second one from vis to unvisited , in each call if we find the neighbor is marked as visited in both vis  & bathvis arrays we return cycle detected

-Bfs-> We use the reversed logic in topo sort **If we can't generate topo sort this means we have a cycle as topo sort happens only in DAGs**
So we keep a counter if at the counter = the number of nodes in the graph that means I have generated a TopoSort and the graph is Asyclic.

### Bipartite

>It States that you can color the graph with only 2 color, we color the node with color between 1 and 0 and if we found 2 adjacent nodes get the same color we this is not bipartite one.

-Dfs

-Bfs-> We do the same, and here we observe if there is an odd cycle we the graph is not bipartite

#### Topo Sort

>Linear ordering of vertices such that if there is an edge u->v, u appear before v in that ordering it's applied for DAGs only.

-Dfs-> We use a normal dfs, but the idea is in using stack we recurse and after the recursion ends , we push the node in the stack , so when we pop from the stack we get the nodes ordered as reversed stack nature. it gets us the nodes oredering topologically.

-BFs-> We use Khan's algorithm

1. We count indgree for every element
2. If the indgree of element is 0 we push it in our queue
3. do bfs , we see if the neighbor node hasn't indegree of 0 we do indegree[neighbor]-- , and if it 0 we push it to the queue
4. We keep a vector topo to get every node has the order in getting out on it.

#### Shortest Path

- Undirected-> We use Normal bfs and to get the shortest path we keep updating the distance with smaller one.
- Dirceted-> We do Topo Sort at first , then Sp steps.
- Dijikstra's -> Used to get the shortest path for weighted edges , we keep pushing the nodes in PQ to determine the shortest path for every node & update it.


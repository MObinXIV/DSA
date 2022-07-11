#include<bits/stdc++.h>

using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

  map<Node*, Node*> vis;
    Node* dfs(Node* node) {
        // if the node is NULL simply return NULL
        if(node == NULL) {
            return node;
        }
        // if the node is already present in the vis, then return reference of that node
        if(vis.find(node) != vis.end()) return vis[node];//لو العنصر موجود فعلًا فى الماب بحطه كرفرنس للعنصر بتاعى خطوة الباكتراك 
        
        // make a new node and store the value of original node
        Node* newNode = new Node(node->val);//بلينك عنصرين ببعض عادى فى حالة ان مزرتوش قبل كدا 
        vis[node] = newNode;
        
        // traverse through neighbors of node and push back dfs of each neighbor
        for(Node* edges: node->neighbors) {
            newNode->neighbors.push_back(dfs(edges));
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        Node* clone = dfs(node);
        return clone;
    }
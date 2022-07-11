#include<bits/stdc++.h>
using namespace std;

//We reperesent the binary tree in terms of struct as nodes ( assume the struct represent the node in same way )
struct Node
{
    int data;
    Node*left;
    Node*right;

    Node(int val)
    {
        data=val;
        left=right=NULL;
    }

};
vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>>ans;
    if (root == NULL) return ans ;//base case if the tree is empty 
    queue<Node*>q;//queue to store our levels 
    
    q.push(root);//push the root of the tree to start our traversal
    while(!q.empty())
    
    {
        vector<int>level;//vector to store our current levels 
        int n = q.size();//take the queue size to traverse for each element in the queue
        for (int i =0 ; i< n ; i++)
        {
            Node*node=q.front();//take the front node of the queue
            q.pop();
            if(node->left) q.push(node->left);//store  the left guys of node if exists (our next level)
            if(node->right) q.push(node->right);//store the right guys if exists(our next level)
            level.push_back(node->data);//push the current node of our current level
        }
        ans.push_back(level);//push the level 

    }
    return ans;
}
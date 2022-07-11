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
//Inorder Traversal (left,root,right)
void inOrder(Node*root)
{
    if (root ==NULL)return;//if we reach to the end we return 
    inOrder(root->left);//going to the left of tree 
    cout<<root->data;//printint root
    inOrder(root->right);//going right
    
}
//بعمل ريكرشن ترى بايترايتف
vector<int> inorderTraversal(Node* root) {
        stack<Node*> st; 
        Node* node = root;
        vector<int> inorder; 
        while(true) {
            if(node != NULL) {// Go left till you end
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) break; 
                node = st.top(); 
                st.pop(); 
                inorder.push_back(node->data);//push element 
                node = node->right; // right when you vack
            }  
        }
        return inorder; 
    }
    
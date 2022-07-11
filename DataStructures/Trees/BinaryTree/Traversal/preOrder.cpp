#include<bits/stdc++.h>
using namespace std;

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
//Root/Left/Right
void preOrderTraversal(Node*root)
 {
     if (root == NULL)return; // if root == null (reach the end we return to the previous node)
     cout<<root->data<<" ";//print root 
     preOrderTraversal(root->left);//go left 
     preOrderTraversal(root->right);//Go right
 }


 vector<int> preorderTraversal(Node* root) {
        vector<int> preorder;
        if(root == NULL) return preorder; 
       
        stack<Node*> st; 
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop(); 
            preorder.push_back(root->data); 
            if(root->right != NULL){
                st.push(root->right);
            }
            if(root->left!= NULL){
                st.push(root->left);
            }
        }
        return preorder; 
    }
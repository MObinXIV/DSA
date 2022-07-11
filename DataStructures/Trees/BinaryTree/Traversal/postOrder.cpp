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
//left/right/root
void postOrder(Node*root)
{
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;

}
vector<int> postorderTraversal(Node* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<Node*> st1, st2; 
        st1.push(root); 
        while(!st1.empty()) {
            root = st1.top(); 
            st1.pop();
            st2.push(root); 
            if(root->left != NULL) {
                st1.push(root->left); 
            }
            if(root->right != NULL) {
                st1.push(root->right); 
            }
        }
        while(!st2.empty()) {
            postorder.push_back(st2.top()->data); 
            st2.pop(); 
        }
        return postorder;
    }


    //postorder 1stacks
    vector<int> postorderTraversal(Node* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<Node*> st1;
        Node* current = root;  
        while(current != NULL || !st1.empty()) {
            if(current != NULL)//Go left as far as you can 
            {
                st1.push(current);
                current = current->left;
            }
            else{
                Node* temp = st1.top()->right;//Get the right child
                if (temp == NULL)//I reach my extreme left 
                 {
                    temp = st1.top();
                    st1.pop(); 
                    postorder.push_back(temp->data);
                    while (!st1.empty() && temp == st1.top()->right) 
                    {
                        temp = st1.top();
                        st1.pop(); 
                        postorder.push_back(temp->data);
                    }
                } 
                else //If we have a node we assign it with curr
                {
                    current = temp; 
                }
            }
        }
        return postorder;
    }

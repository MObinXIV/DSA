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
int main()
{
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right= new Node(3);
    root->left->right=new Node(4);


}
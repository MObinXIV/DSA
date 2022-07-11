#include<bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode*left;
    TreeNode*right;

    TreeNode(int data)
    {
        val=data;
        left=right=NULL;
    }

};
bool isSameTree(TreeNode* p, TreeNode* q) {
        // We chcek the rachability of Null case for any one then chcek if it's true for the other one 
        if(p==NULL || q==NULL)return (p==q);//In case of false I return false 

        return (p->val==q->val)&& isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);//Check the value equality & pre traverse

    }
#include<bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int data;
    TreeNode*left;
    TreeNode*right;

    TreeNode(int val)
    {
        data=val;
        left=right=NULL;
    }

};
//For every node I add the left (height)+right(height) and take the maximum one 
 int  height (TreeNode*root, int& diameter )
 {
    if(root == NULL)return 0 ;
    int l=height(root->left,diameter);//Get the left half of the node 
    int r= height(root->right,diameter);//Get the right half 
    diameter = max(diameter,l+r);//update 
    return 1+ max(l,r);//Normal height


 }
 int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        height(root,dia);
        return dia;
    }
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

bool hasPathSum(TreeNode* root, int targetSum) {
        if(root->val==NULL)return false;
        targetSum-=root->val;
        if(targetSum==0 && root->left==NULL && root->right==NULL)return true;//if I reach the leaf node & I found NUll
        bool left=hasPathSum(root->left,targetSum);//traverse left 
        bool right=hasPathSum(root->left,targetSum);//treaverse right
        return left||right;//If any one returns true I'm true always 
    }

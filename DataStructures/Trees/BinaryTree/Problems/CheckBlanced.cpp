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
//For  Every node  height(left)-height(right)<=1
int dfs (TreeNode * root)
{
    if(root ==NULL)return 0;

    int left = dfs(root->left);
    //check if the height for the left is not valid before we even continue
    if(left==-1)return -1;
    int right=dfs(root->right);
    if(right==-1)return -1;
    if(abs(left-right)>1)return -1;
    return  1+max(left,right);
}
bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }

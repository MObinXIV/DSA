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
/*
Same as diameter problem in addition we add the current node for the path
and reguarley update 
*/

int maxPathDown(TreeNode*root,int& maxi)
{
    if(root == NULL)return 0;
    //To avoid neg cases we replace them with 0
    int l = max(0, maxPathDown(root->left,maxi));
    int r = max(0 , maxPathDown(root->right,maxi));
    maxi=max(maxi,l+r+root->val);
    return root->val+max(l,r);
    
}

int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathDown(root,maxi);
        return maxi;
    }
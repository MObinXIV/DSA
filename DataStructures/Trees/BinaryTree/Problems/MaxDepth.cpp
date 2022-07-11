//The height of Binary tree 
#include<bits/stdc++.h>

using namespace std;
int maxDepth(TreeNode* root) {
        
    if (root ==NULL)
        return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return max(l,r)+1;
    
    }
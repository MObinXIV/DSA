#include<bits/stdc++.h>

using namespace std;
struct TreeNode {
       int val;
       TreeNode * left;
       TreeNode  *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode  *left, TreeNode  *right) : val(x), left(left), right(right) {}
   };
   TreeNode* searchBST(TreeNode* root, int val) {
       while(root!=NULL && root->val!=val)
       {
            root=val< root->val ?root->left:root->right;
       }
       return root;
        
    }
    //recursive solution
    TreeNode*search(struct TreeNode* root, int val)
{
    // Base Cases: root is null or val is present at root
    if (root == NULL || root->val == val)
       return root;
    
    // val is greater than root's val
    if (root->val < val)
       return search(root->right, val);
 
    // val is smaller than root's val
    return search(root->left, val);
}

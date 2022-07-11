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
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
   TreeNode*solve(TreeNode*root)
   {
        if (root->left == NULL) 
            {
                return root->right;
            } 
            else if (root->right == NULL)
            {
                return root->left;
            } 
            TreeNode* rightChild = root->right;
            TreeNode* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
            return root->left;
   }
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root ==NULL)return NULL;
    if (root->val==key)  return solve(root);
    while (root!=NULL)
    {
        if (root->val >key)
        {
            if (root->left !=NULL && root->val==key)
            {
                root->left=solve(root->left);
                break;
            }
            else
            root=root->left;
        }
        else
        {
              if (root->right !=NULL && root->val==key)
            {
                root->right=solve(root->right);
                break;
            }
            else
            root=root->right;
            
        }

    } 

        
    }
    
int main()
{

}
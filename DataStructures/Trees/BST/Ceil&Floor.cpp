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
int findCeil(TreeNode *root, int val)
{
    int ceil=-1;
    while(root)
    {
        if (root->val==val)
        {
            ceil=root->val;
            return ceil;

        }
        if (val>root->val)
        {
            root=root->right;
        }
        else
        {
            ceil=root->val;
            root=root->left;
        }
    }
    return ceil;
}

int floorInBST(TreeNode* root, int val)
{
    int floor = -1; 
    while (root) {
 
        if (root->val == val) {
            floor = root->val;
            return floor;
        }
 
        if (val > root->val) {
            floor = root->val;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return floor;
}

//Recursive solution 
int Ceil(TreeNode* root, int input)
{
    // Base case
    if (root == NULL)
        return -1;
 
    // We found equal val
    if (root->val == input)
        return root->val;
 
    // If root's val is smaller, ceil must be in right subtree
    if (root->val < input)
        return Ceil(root->right, input);
 
    // Else, either left subtree or root has the ceil value
    int ceil = Ceil(root->left, input);
    return (ceil >= input) ? ceil : root->val;
}


int Floor(TreeNode*root,int input)
{
    if (root==NULL)return -1;
    if (root->val==input)return root->val;
    if(root->val>input) return(root->left,input);
    int floor=Floor(root->right,input);
    return (floor <= input) ? floor : root->val;
}

int main()

{

}
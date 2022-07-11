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
//Normal Level Order Traversal with one change
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if (root ==NULL)return res;
        bool LR=true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>row(size);
            for (int i = 0 ; i < size;i++)
            {
                TreeNode*node=q.front();
                q.pop();
                //The current step Is so important here we reverse
                int ind = (LR)? i : (size-1-i);//here I chceck if the flag is true so I return i with no change else  I reverse 
                row[ind]=node->val;
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);

            }
             //Change The flag value after I finish 
            LR=!LR;
            res.push_back(row);

        }
        return res;
       
    }
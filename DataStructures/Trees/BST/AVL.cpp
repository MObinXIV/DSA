#include<iostream>

using namespace std;
class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};
class AVLTree
{
    TreeNode * root;
  AVLTree() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
  int height(TreeNode*r)
  {
      if (r==NULL)return 0;
      int left=height(r->left);
      int right=height(r->right);
      return 1+max(left,right);
  }
  int getBalance(TreeNode*root)
  {
      if(root==NULL)return -1;
      return height(root->left)-height(root->right);
  }
  TreeNode*rightRotate(TreeNode*root)
  {
      TreeNode*x=root->left;
      TreeNode*y=x->right;
      x->right=root;
      root->left=y;
      return x;
  }
  TreeNode*leftRotate(TreeNode*root)
  {
      TreeNode*n=root->right;
      TreeNode*l=n->left;
      n->left=root;
      root->right=l;
      return n;
  }
  TreeNode*insert(TreeNode * r, TreeNode * new_node)
  {
      if (r==NULL)
      {
          r=new_node;
          cout<<"haahaoha \n";
          return r;
      }
      if (new_node -> value < r -> value) {
      r -> left = insert(r -> left, new_node);
    } else if (new_node -> value > r -> value) {
      r -> right = insert(r -> right, new_node);
    } else {
      cout << "No duplicate values allowed!" << endl;
      return r;
    }
    int bf= getBalance(r);
    //leftBalanace
    if (bf>1 && new_node->value < r->left->value)
    return rightRotate(r);
    // Right Right Case  
    if (bf < -1 && new_node -> value > r -> right -> value)
      return leftRotate(r);
      // Left Right Case 
      if (bf>1 && new_node->value >r->left->value)
      {
        r->left=leftRotate(r->left);
        return rightRotate(r);
      }
      // Right Left Case  
    if (bf < -1 && new_node -> value < r -> right -> value) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }
    
  }
  TreeNode * deleteNode(TreeNode * r, int v) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValueNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> value = temp -> value;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    }

    int bf = getBalance(r);
    // Left Left Imbalance/Case or Right rotation 
    if (bf == 2 && getBalance(r -> left) >= 0)
      return rightRotate(r);
    // Left Right Imbalance/Case or LR rotation 
    else if (bf == 2 && getBalance(r -> left) == -1) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation	
    else if (bf == -2 && getBalance(r -> right) <= -0)
      return leftRotate(r);
    // Right Left Imbalance/Case or RL rotation 
    else if (bf == -2 && getBalance(r -> right) == 1) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    return r;
  }
TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }
};

int main()
{

}
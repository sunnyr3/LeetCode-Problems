/*
Invert a binary tree.

Example:
Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    void invert(TreeNode *root) {
        if (!root->left && !root->right) return;
        
        if (!root->left && root->right) {
            root->left = root->right;
            root->right = NULL;
        }
        
        else if (root->left && !root->right) {
            root->right = root->left;
            root->left = NULL;
        }
        
        else {
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
        
        if (root->left) invert(root->left);
        if (root->right) invert(root->right);
        
        return;
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        
        invert(root);
        return root;
    }
};
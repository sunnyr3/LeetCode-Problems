/*
Given a binary trrr, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
1. The left subtree of a node contains only nodes with keys LESS THAN the node's key.
2. The right subtree of a node contains only nodes with keys GREATER THAN the node's key.
3. Both the left and right subtrees must also be binary search trees.

Example 1:
Input:
    2
   / \
  1   3
Output: true

Example 2:
    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
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
public:
    void inOrderTraversal(TreeNode* root, vector<int>& v) {
        if (root->left) inOrderTraversal(root->left, v);
        v.push_back(root->val);
        if (root->right) inOrderTraversal(root->right, v);
        return;
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        
        vector<int> v;
        inOrderTraversal(root, v);
        for (int i = 0; i < v.size()-1; i++) {
            if (v[i] >= v[i+1]) return false;
        }
        
        return true;
    }
};